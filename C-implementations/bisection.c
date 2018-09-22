#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define r 2.718281828
double compute(double x){
    return x*x-9;
}

int main()
{
    double a,b,c;
    double limit;
    double func_c;
    int iter=0;

    printf("Enter left boundary value, a: ");
    scanf("%lf",&a);
    printf("Enter right boundary value, b: ");
    scanf("%lf",&b);

    double func_a=compute(a);
    double func_b=compute(b);
    printf("\n");
    
    if(func_a/fabs(func_a)*(func_b/fabs(func_b))<0){
        printf("[Msg] roots exist in the given boundary");
    }else{
        printf("[Msg] root doesn't exist in the given boundary");
        exit(0);
    }
    printf("\n");

    printf("\nEnter required accuracy: ");
    scanf("%lf",&limit);

    printf("Iter              a                  b                  c                  f(c)\n");
    printf("------------------------------------------------------------------------------\n");
    while(fabs(a-b)>limit){
        iter++;
        c=(a+b)/2.0;
        func_c=compute(c);
        
		printf("%3d %18lf %18lf %18lf %18lf\n",iter,a,b,c,func_c);
        if(func_c==0){
            break;
        }
        else if((func_c/fabs(func_c))*(func_a/fabs(func_a))<0)
            b=c;
        else{a=c;}
    }
    printf("The root of the equation is %lf",c);
    return 0;
}
