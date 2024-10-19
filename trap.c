//  Trapezoidal Method
#include<iostrem>
#include<cmath>
using namespace std;
float f(float);
float trap()
{
int n,i,j;
float h = 0.01,a = 0,b = 1,x[1000000],y[1000000],sum=0,inte;

n = (b-a)/h;
// Taking X Data 
for(i=0;i<=n;i++)
{
x[i] = a+h*i;
}
// Taking Y Data
for(i=0;i<=n;i++)
{
y[i] = f(x[i]);
printf("%f\n",y[i]);
}

for(i=1;i<n;i++)
{
sum = sum+y[i];
}
//printf("f = %f\n",sum);
inte = (h*(y[0]+y[n]+2*sum))/2;
printf("\nThe answer is: %f\n", inte);
//printf("\nThe process is complete successfully\n");
}

void main()
{
	trap();
}

float f(float z)
{
float y;
y = pow(1/(M_PI),1/4)*sqrt(2)*z*exp(-z*z/2);
return y;
}



