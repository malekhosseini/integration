#define xi    x0+i*dx   //یک تعریف پیش پردازنده که پیش از کامپایل برنامه جایگزین میشود
#include <iostream>
#include <cmath>
using namespace std;
/// @brief این تابعی است که انتگرال آن باید محاسبه شود
/// @param x مقدار ورودی متغیر مستقل تابع
/// @return مقدار تابع در نقطه داده شده
double f(double x)
{
    return pow(x,3)-pow(x,2)+x;
}
/// @brief این تابع به روش سیمپسون سه نقطه‌ای مقدار انتگرال یک تابع را بدست می‌آورد
/// @param x0 ابتدای بازه انتگرال گیری
/// @param xn انتهای بازه انتگرال گیری
/// @param n تعداد نقاط در روش سیمپسون
/// @return 
double smp(double x0,double xn,int n)
{
    double sum1=0.0,sum2=0.0;
    if(!(n&1)) n++;//اگر تعداد زوج بود یکی به آن اضافه کن تا فرد شود
    double dx=(xn-x0)/n;
    for(int i=1;i<n-1;i=i+2)
    {
        sum1=sum1 + f(xi);
    }
    for(int i=2;i<n-1;i=i+2)
    {
        sum2=sum2 + f(xi);
    }
    return (sum1*4+sum2*2+f(x0)+f(xn))*dx/3;
}
int main()
{
    double sum=0;
    double a=-20,b=10.0,step,pi=3.141592654;
    int m=100; /// تعداد نقاطی که تابع نهایی در آن نقاط محاسبه خواهد شد
    step=(b-a)/m; ///گام بین نقاط متغیر مستقل که در آنها باید مقدار تابع نهایی حساب شود
    b=a; ///برای اینکه در گام اوب شرایط اشتباه نشود
    for(int i=0;i<=m;i++)
    {
        a=b;
        b=a+step;
        sum = sum+ smp(a,b,m);
        cout<<b<<" , "<<sum<<endl;  /// چاپ مقادیر مستقل و مقدار تابع انتگرال در خروجی
    }
    return 1;
}