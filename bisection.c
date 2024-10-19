// Bisection method  for root finding 


#include<stdio.h>

#include<math.h>

#include<stdlib.h>

float f(float);  // FUNCTION FOR ROOT


float e(float); // FUNCTION  FOR ENERGY


void main()

{
	int i;

	float h=1,m=1,v0 = 4,a = 2;

	float z0 = (a*sqrt(2*m*v0))/h;

	float b[100],x=1.3,y=1.5,z,fx,fy,fz,error;

	b[0] = 0;

	// Applying Bisection Method

	for(i=1;i<=15;i++)
	{
		z = (x+y)/2;
		fx = f(x);
		fy = f(y);
		fz = f(z);
		if(fx*fz<0)
		{
			y = z;
		}
		else
		{
			x = z;
		}
		b[i] = z;
		error = fabs(((b[i]-b[i-1])/b[i]))*100;
		printf("The iteration no. is: %d \n",i);               
		printf("The error is: %f \n" , error);
		printf("The value at %d iteration is: %f \n",i,z);
	}
	printf("\n\n");
	printf("The value at final  %d iteration is: %f \n",i,z);
	printf("The energy is: %f\n", e(z));
}

float f(float x)
{
	float h=1,m=1,v0 = 4,a = 2;
	float z0 = (a*sqrt(2*m*v0))/h;
	float w;
	w = sqrt(pow((z0/x),2)-1)-tan(x);
	return w;
}

float e(float z)
{
	float h=1,m=1,v0 = 4,a = 2;
	return (z*z*h*h/(2*m*a*a))-v0;
}
