// Rohit Kumar (V22133)
// Program For Calculating Translation in maxima of Ground state of SHO 

#include<stdio.h>
#include<math.h>

// Function for Richardson Formula 
float richard(float y1,float y2,float h)
{
	return (y2-y1)/(2*h);
}


void main()
{
	float h = 0.025;      // Step size 

	float x[100],y[100],z[100],b[100];

	FILE *fp;
	FILE *out;
	fp = fopen("qho.dat","r");
	out = fopen("shift.dat","w");
	float a ;                 // Amount of translation 
	printf("Enter the amount of translation : ");
	scanf("%f",&a);
	// Index Variable 
	int i,n = 0;
	// Reading Data From Input file 
	while(1)
	{
		fscanf(fp,"%f %f\n",&x[n],&y[n]);    // Storing value in an array 
		if(feof(fp))  
			break;  
		n++;
	}
	// For calculating Numerical Derivative 
	for(i=0;i<=n;i++)
	{
		z[i] = richard(y[i-1],y[i+1],h);
	}

	// For calculating translation 
	for(i=0;i<=n;i++)
	{
		b[i] = y[i]-a*z[i];
		fprintf(out,"%f\t%f\n",x[i],b[i]);
	}
	printf("The maxima of ground state is at %f and before and after translation it is :%f %f respectively \n",x[10],y[10],b[10]);
	fclose(out);
}
