// Linear Regression Program   End Sem Ans 1

#include<stdio.h>

#include<math.h>

 float f(float x)
 {
 return (1/(x*x));
 }
 
 float g(float x)
 {
 return (1/x);
 }
 
 float h(float x)
 {
 float bmax = 10.060746,qs = 2.037191;
 
return ((bmax*x*x)/(qs+x*x));
 }

  void main()
  {
         float x[100],y[100],sumx = 0,sumy = 0,sumxy = 0,sumx2 = 0;
         
         float b[100],q[100],m,c,bmax,qs;
         
         
         int n = 5,i;
         
         FILE *fp;
         
         fp = fopen("ans1.dat","r");
         
         i = 0;
         
// Reading Values from file

  for(i=0;i<5;i++)
  
{
	  fscanf(fp,"%f %f",&q[i],&b[i]);
	  
}
       for(i=0;i<5;i++)
       {
       
       x[i] = f(q[i]);
       
       y[i] = g(b[i]);
       
       }
          
  // Caluculating sums
  
          for(i=0;i<n;i++)
          
{
	  sumx+=x[i];
	  
	  sumy+=y[i];
	  
	  sumxy+=x[i]*y[i];
	  
	  sumx2+=x[i]*x[i];
}
	m = (n*sumxy-sumx*sumy)/(n*sumx2-sumx*sumx);
	
	c = (sumy-m*sumx)/n;
	
	bmax = 1/c;
	
	qs = m*bmax;
	
	printf("\nThe value of m and c is: %f  %f  respectively.\n",m, c);
	
	printf("\nThe value of bmax and qs is: %f  %f  respectively.\n",bmax, qs);
	
	printf("\nThe value of growth rate is: %2.10f\n\n",h(2));
  }


