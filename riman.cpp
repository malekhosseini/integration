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
    int n=1000;
    double dx=(xn-x0)/n;
    for(int i=0;i<n;i++)
    {
        sum=sum + f(xi);
    }
    sum=sum*dx;

cout<< "sum= "<<sum<<endl;
return 1;
}