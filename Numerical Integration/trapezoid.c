#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
float funct(float a);
int main()
{
	FILE *fptr;
    float x,h,a,b,sum;
    
	fptr = fopen("input.txt", "r");
	if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
	
	fscanf(fptr,"%f%f%f",&a,&b,&h);
	
	printf("Data Found from File!\na : %f\nb : %f\nh : %f\n",a,b,h);
    
        sum=0;
        x=a;
        while(x<=b)
        {
        	if(x==a || x==b){
        		sum+=funct(x);
			}else{
				sum+=2*funct(x);
			}
            x=x+h;
        }
        printf("\nThe integration is: %f\n",sum*h/2);
	
    getch();
    return 0;
}

float funct(float x)
{
    return 1/(1+x*x);
}

