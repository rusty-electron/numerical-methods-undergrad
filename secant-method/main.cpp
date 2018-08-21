#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <iomanip>
using namespace std;

double compute(double x){
    return cos(x) + 2*sin(x) + x*x;
}
int main()
{
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

    if(func_a/fabs(func_a)*(func_b/fabs(func_b))<0){
        cout<<"[Msg] roots exist in the given boundary";
    }else{
        cout<<"[Msg] root doesn't exist in the given boundary";
        exit(0);
    }
    cout<<endl;

    cout<<"\nEnter required accuracy: ";
    cin>>limit;

    cout<<"Iter"<<setw(14)<<"a"<<setw(18)<<"b"<<setw(18)<<"c"<<setw(18)<<"f(c)"<<setw(18)<<"|c'-c|"<<endl;
    cout<<"------------------------------------------------------------------------------"<<endl;
    while(abs(a-b)>limit){
        iter++;
        c=b-(b-a)/(func_b-func_a)*func_b;
        func_c=compute(c);
        a=b;
        b=c;
        func_a=compute(a);
        func_b=compute(b);
        cout<<setw(3)<<iter<<setw(18)<<a<<setw(18)<<b<<setw(18)<<c<<setw(18)<<func_c<<setw(18)<<fabs(a-b)<<endl;

        if(func_c==0){
            break;
        }
    }
    cout<<endl<<"The root of the equation is "<<c;
    return 0;
}



