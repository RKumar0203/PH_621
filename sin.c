#include <stdio.h>
#include <math.h>
#include <fftw3.h>

#define N 64 // Number of samples
#define PI 3.14159265358979323846

int main() {
    // Initialize FFTW
    fftw_complex *in, *out;
    fftw_plan plan;
    
    in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N+1);
    out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex) * N+1);
    plan = fftw_plan_dft_1d(N, in, out, FFTW_FORWARD, FFTW_ESTIMATE);
    
    // Generate input data (sine wave)
    for (int i = 0; i <= N; i++) {
        double x = PI * i / N;
        in[i][0] = sin(x); // Real part
        in[i][1] = 0;      // Imaginary part
    }
    
    // Perform FFT
    fftw_execute(plan);
    
    // Print the results
    printf("Frequency domain representation (Real and Imaginary parts):\n");
    for (int i = 0; i <= N; i++) {
        printf("[%d] Real: %f, Imag: %f\n", i, out[i][0], out[i][1]);
    }
    
    // Clean up
    fftw_destroy_plan(plan);
    fftw_free(in);
    fftw_free(out);

    return 0;
}

