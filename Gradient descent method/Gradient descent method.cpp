

#include <iostream>
#include <math.h>
//ax+by+e^(cx^2+dy^2)
//2c*x*e^(cx^2+dy^2)+a
//2d*y*e^(cx^2+dy^2)-b
const double a = 4, b = -1.1, c = 0.16, d = 0.14;
double Func(const double x, const double y)
{
    return a * x + b * y + exp(c * pow(x, 2) + d * pow(y, 2));
}
double DerivativeByX(const double x,const double y)
{
    return 2 * c * x * exp(c * pow(x, 2) + d * pow(y, 2)) + a;
}
double DerivativeByY(const double x, const double y)
{
    return 2 * d * y * exp(c * pow(x, 2) + d * pow(y, 2)) +b;
}
int main()
{
    const double e = 0.0001;
    double alpha = 1, x = 0,y=0;
    std::cout << "f(" << x << " , " << y << ")= " << Func(x, y) << std::endl;
    while (abs(sqrt(pow(DerivativeByX(x,y),2)+ pow(DerivativeByY(x, y), 2)))>=e
        ||(abs(DerivativeByX(x,y))>=e/2 && abs(DerivativeByY(x, y) >= e / 2)))
    {
        double NewX = x - alpha * DerivativeByX(x, y);
        double NewY = y - alpha * DerivativeByY(x, y);
        if (Func(NewX, NewY) > Func(x, y))
        {
            alpha = alpha / 2;
        }
        else
        {
            x = NewX;
            y = NewY;
        }
    }
    std::cout <<"f("<<x<<" , "<<y<<")= "<<Func(x,y) << std::endl;
    return 0;
}

