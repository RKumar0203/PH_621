// SIMPSON 1/3 METHOD 

#include<stdio.h>
#include<math.h>

float f(float z)
{
	return 2*(sin(M_PI*z)*sin(M_PI*z))*z;
}

void main()
{
	int n,i;
	float x[100],y[100],sum3 =0,rsum = 0,sum = 0,ans;
	float a,b,h= 0.01;
	printf("Enter your upper and lower limit a and b: ");
	scanf("%f%f",&a,&b);
	n = (b-a)/h;
	//Genrating x array
	for(i=0;i<=n;i++)
	{
		x[i] = a+i*h;

		y[i] = f(x[i]);

		printf("%f  %f\n",x[i],y[i]);
	}

	// calculating sum of multiple of 3
	for(i=3;i<=n-1;i+=3)
	{
		sum3+=y[i];
	}
	//calculating total sum

	for(i=1;i<n;i++)
	{

		sum+=y[i];

	}
	rsum = sum - sum3;

	ans = 3*h*(y[0]+y[n]+3*rsum+2*sum3)/8;

	printf("The answer is: %f\n",ans);

}



