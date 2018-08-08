#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

double compute(double x){
    return x*x*x-x-11;
}
int main()
{
    //Equation to be solved: x*x*x-x-11=0
    double a,b,c;
    double limit;
    double func_c;

    cout<<"Enter left boundary value, a: ";
    cin>>a;
    cout<<"Enter right boundary value, b: ";
    cin>>b;

    cout<<"Enter required accuracy: ";
    cin>>limit;

    //Check for root presence
    double func_a=compute(a);
    double func_b=compute(b);

    if(func_a<0 && func_b>0){
        cout<<"[Msg] roots exist in the given boundary";
    }else{
        cout<<"[Msg] root doesn't exist in the given boundary";
    }

    while(abs(a-b)>limit){
        c=(a+b)/2;
        func_c=compute(c);
        cout<<"c: "<<c<<" f(c): "<<func_c<<endl;

        if(func_c>0)
            b=c;
        else if(func_c==0){
            cout<<c;
            exit(0);
        }else{a=c;}
    }
    cout<<c;
    return 0;
}



