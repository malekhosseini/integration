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
    double sum=0;
    double x0=0,xn=3.141592654;
    int n=10;
    double dx=(xn-x0)/n;
    sum = (f(x0)+f(xn))*0.5;
    for(int i=1;i<n-1;i++)
    {
        sum=sum + f(xi);
    }
    sum=sum*dx;

cout<< "sum= "<<sum<<endl;
return 1;
}