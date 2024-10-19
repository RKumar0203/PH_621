// Newton Raphson Method With Air resistence
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

float f(float t)
{
	float k = 0.2,g1= 9.8;
	return ((((25*k)+g1)*(1-exp(-(k*t))))/pow(k,2))-((g1*t)/k);
}
float g(float t)
{
	float k = 0.2,g1 = 9.8;
	return ((((25*k)+g1)*(exp(-(k*t))))/k)-(g1/k);
}


void main()
{ 

	float x0 = 4,x1,fx0,fx1,tol = 0.001;
	int i=0;

	while(1)
	{
		fx0 = f(x0);
		fx1 = g(x0);
		x1 = x0-((fx0)/(fx1));
		if(fabs(x0-x1)<tol)
			break;
		x0 = x1;
		i++;
	}

	printf("The value of time of flight is: %f\n", x0);




}



