#include<stdio.h>

#include<math.h>


float f(float x,float y)		// For Numerical Solution

{

	float a = 0.5024,b = 0.001;

	return -(a*b*(y-10));

}


float g(float x)		//  For Analytical Solution 
			
{

	float a = 0.5024,b = 0.001;

	return 10+1990*exp(-a*b*x);

}

void main()
{
FILE *fp;

  float x[10000] = {0.0},y[100000] = {0.0},h = 1.0,d,m;

    float k1 = 0.0,k2 = 0.0,k3 = 0.0 ,k4 = 0.0,tol = 0.000001;

       int i;

       	x[0] = 0;

    	   y[0] = 2000;

              fp = fopen("data.txt","w");		// For printing data in File 

                 printf("RK4 Method\n");

           for(i=1;i<=100000;i++)  	 	// Applying loop for iterations 

{

	k1 = f(x[i-1],y[i-1]);

	k2 = f(x[i-1]+h/2,y[i-1]+h*k1/2);

	k3 = f(x[i-1]+h/2,y[i-1]+h*k2/2);

	k4 = f(x[i-1]+h,y[i-1]+h*k3);

	y[i] = y[i-1]+h*(k1+2*k3+2*k2+k4)/6;

	d = fabs(y[i]-y[i-1]);

	if(d<tol)

	{

	break;

	}


	x[i] = x[i-1] + h;

	m = x[i];



	fprintf(fp,"%f\t%f\t%f\n",x[i],y[i],g(x[i]));

}


printf("The value of time at which temperature is equal to surrounding temperature is : %f\n", m);
	
}
