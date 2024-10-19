// Rk 2 Method 

#include<stdio.h>
#include<math.h>

float f(float x,float y)
{
	return 4*exp(0.8*x)-(0.5)*y;
}





void main()
{
float x0 = 0,y0 = 2,h = 1,k1,k2,y1;
int i;
for(i=0;i<4;i++)
{
k1 = h*f(x0,y0);
k2 = h*f(x0+h,y0+k1);
y1 = y0+(k1+k2)/2;
printf("The value is %f\n",y1);
y0 = y1;
x0 = x0+h;
}
}

