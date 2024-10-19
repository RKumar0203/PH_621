// Langrange Interpolation Method
#include<stdio.h>
#include<math.h>
float f(float);
void main()
{
	float x[1000],y[1000],X[100] = {3,15,27,39,51},th;
	int i,n,j,k;
	float term =1 ,sum =0;
	FILE *fp;
	fp = fopen("lang1.txt","r");   // Reading data from file 
	n = 0;
	while(1)
	{
		fscanf(fp,"%f %f",&x[n],&y[n]);
		if(feof(fp))
			break;
		n++;
	}
	fclose(fp);
	printf("%d\n",n);
	// Applying langrange Interpolation Formula 
	for(k=0;k<5;k++)
	{
		sum = 0;
		th = f(X[k]);

		for(i=0;i<n;i++)
		{
			term = 1;
			for(j=0;j<n;j++)
			{
				if(i!=j)
					term = term*(X[k]-x[j])/(x[i]-x[j]);
			}
			sum = sum+term*y[i];                                   
		}
		printf("\n");
		printf("calculating value at   :%f \n", X[k]);
		printf("Interpolation value is : %f\n",sum);
		printf("Value from function is : %f\n",th);
		printf("\n");
	}

}

float f(float X)
{
	float z = (30*M_PI)/180,u = 2815.15,g = 127137.6,m;
	m = tan(z)*X-g*X*X/(2*u*u*cos(z)*cos(z));
	return m;
}



