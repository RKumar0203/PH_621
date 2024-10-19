#include<stdio.h>
#include<math.h>
#include<stdlib.h>


float f(float x,float y)
{
return (4*exp(0.8*x)-0.5*y);
}

float th(float x)
{
return (4/1.3)*(exp(0.8*x)-exp(-0.5*x)+2*exp(-0.5*x));
}

void main()
{
int i;
float x[100] = {0},y[100] = {0}, h = 1;
float k1,k2,k3,k4;
x[0] = 0;
y[0] = 2;
for(i=1;i<=4;i++)
{
k1 = f(x[i-1],y[i-1]);
k2 = f(x[i-1]+h/2,y[i-1]+h*k1/2);
k3 = f(x[i-1]+h/2,y[i-1]+h*k2/2);
k4 = f(x[i-1]+h,y[i-1]+h*k3);
y[i] = y[i-1]+h*(k1+2*k2+2*k3+k4)/6;
x[i] = x[i-1]+h;
printf("%f\t%f\t%f\n",x[i],y[i],th(x[i]));
}
}
