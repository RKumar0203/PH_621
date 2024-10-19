// Euler Method  for falling parachutist Method

#include<stdio.h>
#include<math.h>

void main()
{
	int i;
	float m = 68.1,k = 12.5,g = 9.8,h,tol = 0.000000001;
	float v0 = 0,v1;
	FILE *fp;
	fp = fopen("euler.dat","w");

	printf("Enter value of step size: ");

	scanf("%f",&h);

	printf("\n");

	// Applying loop for calculating velocity

	for(i=0;i<=100000;i++)
	{
		v1 = v0+(g-(k/m)*v0)*h;

		fprintf(fp,"%f\n",v1);              // Printing values in the file

		if(fabs(v0-v1)<tol)                 // Breaking condition

			break;
		v0 = v1;

		printf("The number of iteration is: %d\n",i);

		printf("The value of velocity is: %f \n\n",v1);
	}

	fclose(fp);
}
