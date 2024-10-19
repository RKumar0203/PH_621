// Newton Raphson Method Without Air resistence

#include<stdio.h>

#include<math.h>

float f(float z )
{
	return 25*z-(0.5*9.8*z*z);
}

float g(float z)
{
	return 25-(9.8*z);
}


void main()
{ 

	float x0 = 4,x1,fx0,fx1,tol = 0.001;
	int i=0;

	while(1)			//  applying infinite loop
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

	printf("The root is find after %d iterations \n",i);

}


