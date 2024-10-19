// Linear Regression Program For Photo-Electric Effect 

#include<stdio.h>

#include<math.h>

float f(float);

void main()
{
	float x[100],y[100],sumx = 0,sumy = 0,sumxy = 0,sumx2 = 0;

	float a,b;

	int n,i;

	FILE *fp;

	fp = fopen("fit.dat","r");

	i = 0;

	// Reading Values from file

	while(1)

	{
		fscanf(fp,"%f %f",&x[i],&y[i]);

		if(feof(fp))

			break;

		i++;
	}
	n = i;

	// Caluculating sums

	for(i=0;i<n;i++)

	{
		sumx+=x[i];

		sumy+=y[i];

		sumxy+=x[i]*y[i];

		sumx2+=x[i]*x[i];
	}
	a = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);

	b = (sumy-a*sumx)/n;

	printf("\nThe value of slope and intercept is: %f  %f  respectively.\n",a, b);

	printf("\nThe value of  relative error at 7eV is: %f\n\n" ,(2.33-f(7))/2.33);
}

float f(float x)

{

	return (1.002326*x-4.757676);

}
