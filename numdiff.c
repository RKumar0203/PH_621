// NUMERICAL DIFFERENTIATION Program

#include<stdio.h>
#include<stdlib.h>
float forward(float y1,float y2,float h)
{
return (y2-y1)/h;
}

float backward(float y1,float y2,float h)
{
return (y2-y1)/h;
}

float centered(float y1,float y2,float h)
{
return (y2-y1)/(2*h);
}

void main()
{
FILE *fp;
float lower_limit = 1,upper_limit = 5,h = 0.1,pi = 3.14159;
float n = (upper_limit - lower_limit)/h;
int i,m;
printf("%d\n",abs(n));
m = abs(n);
float v[m],x[m],f[m],b[m],c[m];
fp = fopen("field.txt", "w");

for(i=0;i<=m;i++)
{
x[i] = 1+i*h;
v[i] = 1/(4*pi*x[i]);
printf("%f\n",v[i]);
}

for(i=0;i<=m;i++)
{
f[i] = forward(v[i+1],v[i],h);
if(i!=0)
{
b[i] = backward(v[i],v[i-1],h);
c[i] = centered(v[i+1],v[i-1],h);
}
fprintf(fp,"%f\t%f\t%f\t%f\n",x[i],f[i],b[i],c[i]);
}

}
