#include<stdio.h>

float f(float x,float y)
{
return (-y);
}

void main()
{
int i;
float x[100],y[100],h = 0.1;
x[0] = 0;
y[0] = 1;
float k1,k2,k3,k4;
for(i=1;i<=2;i++)
{
k1 = f(x[i-1],y[i-1]);
//printf("%f",k1);
k2 = f(x[i-1]+h/2,y[i-1]+h*k1/2);
//printf("%f\n",k1);
k3 = f(x[i-1]+h/2,y[i-1]+h*k2/2);
k4 = f(x[i-1]+h,y[i-1]+h*k3);
y[i] = y[i-1]+h*(k1+2*k2+2*k3+k4)/6;
x[i] = x[i-1]+h;
printf("%f\t%f\n",x[i],y[i]);
}
}
