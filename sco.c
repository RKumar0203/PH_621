// Rohit Kumar (V22133) 
// Ground State solution for ground state of simple harmonic oscillator 

#include<stdio.h>

#include<math.h>

float f(float x,float y,float z)
{
return z;
}

float g(float x,float y,float z)
{
return y*(x*x-1);
}

void main()
{
FILE  *fp;
fp = fopen("qho.dat","w");            // File to print data 
printf("position\twavefunction\tslope\n\n");
int i;
float x[100],y[100],z[100],h =  0.25;
y[0] = 0.033;
z[0] = 0.08250;
x[0] = -2.5;
int n = 20;
float k1,k2,k3,k4,l1,l2,l3,l4;

// Applying Runge-Kutta Method 

for(i=1;i<n+1;i++)
{
x[i] = x[0]+i*h;


k1= f(x[i-1],y[i-1],z[i-1]);
l1= g(x[i-1],y[i-1],z[i-1]);

k2=f((x[i-1]+(0.5*h)),(y[i-1]+(0.5*h*k1)),(z[i-1]+(0.5*h*l1)));
l2=g((x[i-1]+(0.5*h)),(y[i-1]+(0.5*h*k1)),(z[i-1]+(0.5*h*l1)));

k3=f((x[i-1]+(0.5*h)),(y[i-1]+(0.5*h*k2)),(z[i-1]+(0.5*h*l2)));
l3=g((x[i-1]+(0.5*h)),(y[i-1]+(0.5*h*k2)),(z[i-1]+(0.5*h*l2)));

k4=f((x[i-1]+(h)),(y[i-1]+(h*k3)),(z[i-1]+(h*l3)));
l4=g((x[i-1]+(h)),(y[i-1]+(h*k3)),(z[i-1]+(h*l3)));

y[i]=y[i-1]+((h*(k1+(2*(k2+k3))+k4))/6);
z[i]=z[i-1]+((h*(l1+(2*(l2+l3))+l4))/6);
}
for(i=0;i<n+1;i++)
{
printf("%f\t%f\t%f\n",x[i],y[i],z[i]);
fprintf(fp,"%f\t%f\n",x[i],y[i]);


}
fclose(fp);
}



 
