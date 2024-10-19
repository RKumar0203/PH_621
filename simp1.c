// SIMPSON 1/3 METHOD 

#include<iostream>
#include<cmath>
using namespace std;

float f(float z)
{
	float m;
	m = pow(1/(M_PI),1/4)*sqrt(2)*z*exp(-z*z/2)*pow(1/(M_PI),1/4)*sqrt(2)*z*exp(-z*z/2);
	return m;
}

float simp1()
{
	//FILE *fp;
	//fp = fopen("simp1.txt","w");

	int i,n;
	float x[1000],y[1000],odd_sum =0,even_sum = 0,ans;
	float a,b,h = 0.1;
	cout<<"Enter the Value of a and b"<<endl;

	cin>>a>>b;

	n = (b-a)/h;


	//Genrating x array
	for(i=0;i<=n;i++)
	{
		x[i] = a+i*h;

		y[i] = f(x[i]);

		//fprintf(fp,"%f  %f\n",x[i],y[i]);
	}

	//CALCULATING ODD SUM
	for(i=1;i<=n-1;i+=2)
	{

		odd_sum+=y[i];

	}

	//CALCULATING EVEN SUM

	for(i=2;i<=n-2;i+=2)
	{

		even_sum+=y[i];

	}

	ans = h*(y[0]+y[n]+4*odd_sum+2*even_sum)/3;

	//printf("The answer is: %f \n",ans);
	cout<<"The answer is :"<<ans<<endl;
	//fclose(fp);
}

void main()
{
	simp1();
}



