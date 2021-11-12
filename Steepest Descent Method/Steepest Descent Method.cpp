
#include <iostream>
#include <math.h>
//ax+by+e^(cx^2+dy^2) = func
// 
//2c*x*e^(cx^2+dy^2)+a = DerivativeByX
// 
//2d*y*e^(cx^2+dy^2)-b = DerivativeByY
// 
//4*(x-DerivativeByX*a)-1,1*(y-DerivativeByY*a)+e^(0,16*(x-DerivativeByX*a)^2+0,14*(y-DerivativeByY*a)^2) = f(x^k)
// 
//4*DerivativeByX - 1,1 * DerivativeByY +e^(0,16*(x-DerivativeByX*a)^2+0,14*(y-DerivativeByY*a)^2) +
//+(0,32*(x-DerivativeByX*a)+0,28*(y-DerivativeByY*a))
const double a = 4, b = -1.1, c = 0.16, d = 0.14;
double Func(const double x, const double y)
{
    return a * x + b * y + exp(c * pow(x, 2) + d * pow(y, 2));
}
double DerivativeByX(const double x, const double y)
{
    return 2 * c * x * exp(c * pow(x, 2) + d * pow(y, 2)) + a;
}
double DerivativeByY(const double x, const double y)
{
    return 2 * d * y * exp(c * pow(x, 2) + d * pow(y, 2)) + b;
}

double DerivativeByAlpha(const double x, const double y, const double alpha)
{
    return a * (-DerivativeByX(x, y)) + b * (-DerivativeByY(x, y))
        + exp(c * pow((x - DerivativeByX(x, y) * alpha), 2) + d * pow((y - DerivativeByY(x, y) * alpha), 2))
        * (2 * DerivativeByX(x, y) * (-x + DerivativeByX(x, y) * alpha) * d + 2 * DerivativeByY(x, y) * (-y + DerivativeByY(x, y) * alpha) * d);
}
double GoldenRatio(const double x, const double y)
{
    double ag = x, bg = y;
    while (abs(ag-bg)> 0.1)
    {
        double cg = ag + (1 - 0.618) * (bg - ag);
        double dg = ag + 0.618 * (bg - ag); 
        double fc = DerivativeByAlpha(x, y, cg);
        double fd = DerivativeByAlpha(x, y, dg);
        if (fc >= fd)
        {
            ag = cg;
        }
        else
        {
            bg = dg;
        }
    }
    return abs(ag - bg);
}
int main()
{
    const double e = 0.0001;
    double x = -2, y = 3, alpha;
    while (sqrt(pow(DerivativeByX(x,y),2)+ pow(DerivativeByY(x, y), 2))>e)
    {
        alpha = GoldenRatio(x, y);
        x = x - DerivativeByX(x, y) * alpha;
        y = y - DerivativeByY(x, y) * alpha;
    }
    std::cout << "f(" <<x<<"," << y <<") = "<<Func(x,y) << std::endl;

    return 0;
}

