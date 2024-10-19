#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
	return 4*exp(0.8*x)-0.5*y;
}

void main()
{
	float x[5] = {0},y[5] = {0},z[5] = {0},h = 1.0;
	x[0] = 0.0;
	y[0] = 2.0;
	int i;
	for(i=1;i<=4;i++)
	{
		z[i] =  y[i-1] + h*f(x[i-1],y[i-1]);
		y[i] = y[i-1]+(h/2)*(f(x[i-1],y[i-1])+f(x[i-1]+h,z[i]));
		x[i] = x[i-1]+h;
		printf("%f\t%f\t%f\n",x[i],y[i],z[i]);
	}
}
