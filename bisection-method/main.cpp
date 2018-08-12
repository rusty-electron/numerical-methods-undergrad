#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
#define r 2.718281828
using namespace std;

double compute(double x){
    return ((3*x)+sin(x)-pow(r,x));
}
int main()
{
    //Equation to be solved: x*x*x-x-11=0
    double a,b,c;
    double limit;
    double func_c;
    int iter=0;

    cout<<"Enter left boundary value, a: ";
    cin>>a;
    cout<<"Enter right boundary value, b: ";
    cin>>b;

    double func_a=compute(a);
    double func_b=compute(b);
    cout<<endl;
    //Check for root presence
    if(func_a/fabs(func_a)*(func_b/fabs(func_b))<0){
        cout<<"[Msg] roots exist in the given boundary";
    }else{
        cout<<"[Msg] root doesn't exist in the given boundary";
        exit(0);
    }
    cout<<endl;

    cout<<"\nEnter required accuracy: ";
    cin>>limit;

    cout<<"Iter"<<setw(14)<<"a"<<setw(18)<<"b"<<setw(18)<<"c"<<setw(18)<<"f(c)"<<setw(18)<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    while(abs(a-b)>limit){
        iter++;
        c=(a+b)/2.0;
        func_c=compute(c);
        cout<<setw(3)<<iter<<setw(18)<<a<<setw(18)<<b<<setw(18)<<c<<setw(18)<<func_c<<endl;

        if(func_c==0){
            break;
        }
        else if((func_c/fabs(func_c))*(func_a/fabs(func_a))<0)
            b=c;
        else{a=c;}
    }
    cout<<endl<<"The root of the equation is "<<c;
    return 0;
}



