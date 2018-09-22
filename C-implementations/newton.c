#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double compute(double x){
    return x*x-2*x+1;
}

double derivative(double x){
	return 2*x-2;
}

int main()
{
    double c;
    double limit;
    double func_c,func_d;
    int iter=0;

    printf("Enter first value, x0: ");
    scanf("%lf",&c);

    printf("\n");

    printf("\nEnter required accuracy: ");
    scanf("%lf",&limit);
    
    printf("Iter              x                  f(x)                f'(x)\n");
    printf("---------------------------------------------------------------------------\n");
    
    iter++;
        
    func_c=compute(c);
    func_d=derivative(c);
    c=c-func_c/func_d;
        
	printf("%3d %18lf %18lf %18lf\n",iter,c,func_c,func_d);
    while(abs(func_d)>limit){
        iter++;
        
        func_c=compute(c);
        func_d=derivative(c);
        c=c-func_c/func_d;
        
		printf("%3d %18lf %18lf %18lf\n",iter,c,func_c,func_d);
    }
    printf("The root of the equation is %lf",c);
    return 0;
}
