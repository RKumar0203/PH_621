#include<stdio.h>
#include<math.h>
float f1(float,float,float);
float f2(float,float,float);
void main()
{
	int i,n;
	float h,a,b;
	printf("Enter the lower and upper limits:");
	scanf("%f%f",&a,&b);
	printf("Enter the step-size:");
	scanf("%f",&h);
	n=fabs(a-b)/h;
	float x[n],y1[n],y2[n];
	printf("Enter the initial guess for y1:");
	scanf("%f",&y1[0]);
	printf("Enter the initial guess for y2:");
	scanf("%f",&y2[0]);
	x[0]=a;
	float k11,k21,k31,k41;
	float k12,k22,k32,k42;
	for(i=0;i<n-1;i++)
	{
		x[i+1]=x[i]+h;
	}
	for(i=0;i<n-1;i++)
	{
		k11=f1(x[i],y1[i],y2[i]);
		k12=f2(x[i],y1[i],y2[i]);

		//printf("%f,%f\n",k11,k12);

		k21=f1(x[i]+(h/2),y1[i] + (k11*h/2),y2[i] + (k12*h/2));
		k22=f2(x[i]+(h/2),y1[i] + (k11*h/2),y2[i] + (k12*h/2));

		//printf("%f,%f\n",k21,k22);

		k31=f1(x[i]+(h/2),y1[i] + (k21*h/2),y2[i] + (k22*h/2));
		k32=f2(x[i]+(h/2),y1[i] + (k21*h/2),y2[i] + (k22*h/2));

		//printf("%f,%f\n",k31,k32);

		k41=f1(x[i]+h,y1[i]+(k31*h),y2[i] + (k32*h));
		k42=f2(x[i]+h,y1[i]+(k31*h),y2[i] + (k32*h));

		//printf("%f,%f\n",k41,k42);

		y1[i+1]=y1[i]+h*(k11 + 2*k21 + 2*k31 + k41)/6;
		y2[i+1]=y2[i]+h*(k12 + 2*k22 + 2*k32 + k42)/6;
	}
	printf("Table for y1: \n");
	for(i=0;i<n;i++)
	{
		printf("x[%d]:%f\ty1[%d]:%f\n",i,x[i],i,y1[i]);
	}
	printf("Table for y2: \n");
	for(i=0;i<n;i++)
	{
		printf("x[%d]:%f\ty2[%d]:%f\n",i,x[i],i,y2[i]);
	}
}
float f1(float x,float y1,float y2)
{
	return y2;
}
float f2(float x,float y1,float y2)
{
	return ((x*x)-1)*y1;
}
