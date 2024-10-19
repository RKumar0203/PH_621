// Fourier Transform code for Ground State of 1-D Particle Box
// Rohit Kumar (V22133)

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<fftw3.h>

void main()
{

	int i,L;
	printf("Enter the size of box : ");	// Prompting User to Enter Box Size
	scanf("%d",&L);

	fftw_complex *in,*out;

	fftw_plan my_plan;

	FILE *fp;
	fp = fopen("out.dat","w");	// To Store Data in a file 

	in = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*L);     // For Input Coefficiets
	out = (fftw_complex*) fftw_malloc(sizeof(fftw_complex)*L);	// For Output Coefficients


	for( i = 0;i<=L;i++)
	{
		in[i][0] = sqrt(2)*sin((M_PI*i/L));	// Real Part 
		in[i][1] = 0;				// Imaginary Part 
	}

	printf("\n");
	printf("Input FFT coefficients : \n");
	printf("\n");

	for(i=0;i<=L;i++)
	{
		printf("%3d %f %f \n" , i ,in[i][0],in[i][1]);
	}


	my_plan = fftw_plan_dft_1d(L,in,out,FFTW_FORWARD,FFTW_ESTIMATE);  // Declaring my plan 

	fftw_execute(my_plan);

	printf("\n");
	printf("Output FFT coefficients : \n");
	printf("\n");

	for(i=0;i<=L;i++)
	{
		printf("%3d %12f %12f \n",i, out[i][0],out[i][1]);
		fprintf(fp,"%3d %12f %12f \n",i, out[i][0],out[i][1]);  
	}
	fclose(fp);
	fftw_free(in);
	fftw_free(out);


}
