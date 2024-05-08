#define xi    x0+i*dx
#include <iostream>
#include <cmath>
using namespace std;
double f(double x)
{
    return sin(x);
}
int main()
{
    double sum1=0,sum2=0,sum=0;
    double x0=0,xn=3.141592654;
    int m=13;
    //int n=pow(2,m)+1;
    int n= 2*m +1;
    double dx=(xn-x0)/n;
    for(int i=1;i<n-1;i=i+2)
    {
        sum1=sum1 + f(xi);
    }
    for(int i=2;i<n-1;i=i+2)
    {
        sum2=sum2 + f(xi);
    }
    sum=(sum1*4+sum2*2+f(x0)+f(xn))*dx/3;
    cout<< "sum= "<<sum<<endl;
    return 1;
}