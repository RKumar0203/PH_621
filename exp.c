// Exponential Function Program 

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double  fact(int  i)
{
	if(i==0||i==1)
		return 1;
	else 
		return i*fact(i-1);
}

void main()

{
	int i;
	float fp,fs = 0,tol = 0.01,x;        // Enter x value for 0.025 and 1
	printf("Enter the value of x:  ");
	scanf("%f",&x);
	fp = exp(-x);                        // using inbuilt function 

	for(i=0;i<=170;i++)
	{  

		fs = fs+pow((-x),i)/(fact(i));            // function for power series 

	}

	printf("The value from function is: %f\n\n",fp);

	printf("The value from power series  is: %f\n\n",fs);

	printf("The difference between value from power series and value from in-built function is: %f\n\n",fabs(fp-fs));

}


