#include <stdio.h>
#include <math.h>
#include <fftw3.h>

int main() {
    int i, L;
    printf("Enter the size of box : ");
    scanf("%d", &L);

    // Define arrays for input and output
    fftw_complex in[L+1], out[L+1];

    for (i = 0; i <= L; i++) {
        in[i][0] = sqrt(2) * sin((M_PI * i / L));
        in[i][1] = 0;
    }

    printf("Input FFT coefficients : \n");

    for (i = 0; i <= L; i++) {
        printf("%3d %f %f \n", i, in[i][0], in[i][1]);
    }

    fftw_plan my_plan;
    my_plan = fftw_plan_dft_1d(L, in, out, FFTW_FORWARD, FFTW_ESTIMATE);

    fftw_execute(my_plan);

    printf("Output FFT coefficients : \n");

    for (i = 0; i <= L; i++) {
        printf("%3d %12f %12f \n", i, out[i][0], out[i][1]);
    }

    fftw_destroy_plan(my_plan);

    return 0;
}

