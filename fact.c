#include<stdio.h>

double fact(int  i)

{
if(i==0||i==1)

return 1;

else 

return i*fact(i-1);

}

void main()

{
int x;

printf("Enter the value of x : ");

scanf("%d",&x);

printf("The value of factorial of %d is : %lf\n" , x,fact(x));

}


