#include<stdio.h>

void main()
{
	float x[100],b[100][100],z = 0.5,c,f=0;
	int n,i,j;
	printf("enter the value of n: " );
	scanf("%d",&n);
	printf("Enter your x data: ");
	for(i=0;i<n;i++)
	{
		scanf("%f",&x[i]);
	}
	printf("Enter your y Data:");
	for(j=0;j<n;j++)
	{
		scanf("%f",&b[0][j]);
	}

	// For geneating difference table
	for(i=1;i<=n-1;i++)
	{
		for(j=0;j<=n-i-1;j++)
		{
			b[i][j] = (b[i-1][j+1]-b[i-1][j])/(x[i+j]-x[j]);
			printf("%f\t",b[i][j]);
		}
		printf("\n");
	}
	//For calculating interpolation value
	for(i=0;i<n-1;i++)
	{
		c =1.0;
		for(j=0;j<=i-1;j++)
		{
			c = c*(z-x[j]);
		}
		f = f+c*b[i][0];
	}

	printf("the answer is %f\n ",f); 
}
