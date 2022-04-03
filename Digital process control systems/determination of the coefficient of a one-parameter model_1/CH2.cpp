
#include <iostream>
#include <math.h>


const int N = 20;
void ArrayFillingK(double(&k)[3][3], const double X[N])
{
    for (int i = 0; i < N; i++)
    {
        k[0][0] += pow(X[i], 4);
    }

    for (int i = 0; i < N; i++)
    {
        k[0][1] += pow(X[i], 3);
    }

    for (int i = 0; i < N; i++)
    {
        k[0][2] += pow(X[i], 2);
    }

    k[1][0] = k[0][1];
    k[1][1] = k[0][2];

    for (int i = 0; i < N; i++)
    {
        k[1][2] += X[i];
    }
    k[2][0] = k[0][2];
    k[2][1] = k[1][2];
    k[2][2] = N;
}
void ArrayFillingP(double(&p)[3], const double X[N], const double Y[N])
{
    for (int i = 0; i < N; i++)
    {
        p[0] += Y[i] * pow(X[i], 2);
    }
    for (int i = 0; i < N; i++)
    {
        p[1] += Y[i] * X[i];
    }
    for (int i = 0; i < N; i++)
    {
        p[2] += Y[i];
    }
}
int main()
{
    const double X[N] = { 0, .2, .4,.6,.8,1,1.2,1.4,1.6,1.8,2,2.2,2.4,2.6,2.8,3,3.2,3.4,3.6,3.8 };
    const double Y[N] = { 2.28,2.26,2.19,2.09,1.97,1.85,1.74,1.65,1.666,
        1.58,1.6,1.65,1.71,1.78,1.84,1.87,1.88,1.86,1.8,1.74 };
    double k[3][3] = { 0 };
    ArrayFillingK(k, X);
    double p[3] = { 0 };
    ArrayFillingP(p, X, Y);

    double delta = k[0][0] * (k[1][1] * k[2][2] - k[2][1] * k[1][2]) - 
        k[0][1] * (k[2][2] * k[1][0] - k[2][0] * k[1][2]) +
        k[0][2] * (k[2][1] * k[1][0] - k[2][0] * k[1][1]);

    double delta_A = p[0] * (k[1][1] * k[2][2] - k[2][1] * k[1][2]) -
        k[0][1] * (k[2][2] * p[1] - p[2] * k[1][2]) +
        k[0][2] * (k[2][1] * p[1] - p[2] * k[1][1]);

    double delta_B = k[0][0] * (p[1] * k[2][2] - p[2] * k[1][2]) -
        p[0] * (k[2][2] * k[1][0] - k[2][0] * k[1][2]) +
        k[0][2] * (p[2] * k[1][0] - k[2][0] * p[1]);
    double delta_C = k[0][0] * (k[1][1] * p[2] - k[2][1] * p[1]) -
        k[0][1] * (p[2] * k[1][0] - k[2][0] * p[1]) +
        p[0] * (k[2][1] * k[1][0] - k[2][0] * k[1][1]);

    double a = delta_A / delta;
    double b = delta_B / delta;
    double c = delta_C / delta;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
    double NY[N];
    for (int i = 0; i < N; i++)
    {
        NY[i] = a * pow(X[i],2) + b* X[i] + c;
    }

    for (int i = 0; i < N; i++)
    {
        std::cout << NY[i] << " ";
    }

    double M_waiting = 0;
    for (int i = 0; i < N; i++)
    {
        M_waiting += NY[i];
    }
    M_waiting = M_waiting / N;

    double Sy = 0;
    for (auto i : NY)
    {
        Sy += pow(i - M_waiting, 2);
    }
    Sy = Sy / (N - 2);

    double Sexp = 0;
    for (int i = 0; i < N; i++)
    {
        Sexp += pow(NY[i] - Y[i], 2);
    }
    Sexp = Sexp / (N - 2);

    double F = Sy / Sexp;
    std::cout << std::endl << "F = " << F << std::endl;
    return 0;
}


