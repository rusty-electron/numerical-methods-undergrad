#include <stdio.h>
#include <math.h>
#include <stdlib.h>
float y_prime;

float dfunc(float x, int order){
    switch(order){
        case 1:
            return x - y_prime*y_prime;
            break;
        case 2:
            return 1-2*y_prime*dfunc(x,1);
            break;
        case 3:
            return -2*y_prime*dfunc(x,2)-2*pow(dfunc(x,1),2);
            break;
        case 4:
            return -2*y_prime*dfunc(x,3)-6*dfunc(x,1)*dfunc(x,2);
            break;
        case 5:
            return -2*y_prime*dfunc(x,4)-8*dfunc(x,1)*dfunc(x,3)-6*pow(dfunc(x,2),2);
    }
    return -1;
}

float factorial(int n){
    int i,sum = 1;
    for(i=1;i<=n;i++)
        sum*=i;
    return sum;
}

float taylor(float x){
    int i;
    float ret = y_prime;
    for(i=0;i<5;i++){
        ret+=pow(x,i+1)*dfunc(0,i+1)/factorial(i+1);
    }
    return ret;
}

int main()
{
    float x;
    printf("[Input] Enter value of y(0): ");
    scanf("%f",&y_prime);

    printf("[Input] Enter the value of x: ");
    scanf("%f",&x);

    printf("\n[Output] The solution to the ODE using Taylor series is %f", taylor(x));
    return 0;
}
