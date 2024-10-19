// Langrange Interpolation  Method

#include<stdio.h>
void main()
{
	int n,i,j;
	float x[100],y[100];
	float X,term = 1,sum = 0;

	// Taking Data from user

	printf("Enter value of obeservations: ");
	scanf("%d",&n);

	printf("Enter value of X\n");
	scanf("%f",&X);

	printf("Enter the x Data\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("Enter correspnding y data:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&y[i]);
	}
	// Langrange coefficients
	for(i=0;i<n;i++)
	{
		term =1;
		for(j=0;j<n;j++)
		{
			if(i!=j)
			{
				term = term*((X-x[j])/(x[i]-x[j]));
			}
		}
		sum = sum+term*y[i];

	}
	printf("the answer is %f  \n", sum);
}
