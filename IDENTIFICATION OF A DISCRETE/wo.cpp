// 2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;
double maxi(const double a, const double b)
{
	return (a < b) ? b : a;
}
int main()
{
	srand(time(0));
	const int N = 300;
	const double T1 = 6, T2 = 2;
	const double T0 = 0.1;
	const double k = 4;
	const double Tao = 2;
	const double p = 0.2;

	double d = Tao / T0;
	double T11 = T1 + T2;
	double T22 = T1 * T2;

	double a1 = (T11 * T0 + 2 * T22 - pow(T0, 2)) / (T22 + T11 * T0);
	double a2 = -T22 / (T22 + T11 * T0);
	double b = (k * pow(T0, 2)) / (T22 + T11 * T0);

	double u[N] = { 0 };
	double y[N] = { 0 };
	double ys[N] = { 0 };

	for (int i = maxi(2, d + 1); i < N - 1; i++)
	{
		u[i] = 1;
		int x = i - 1 - d;
		y[i + 1] = a1 * y[i - 1] + a2 * y[i - 2] + b * u[x];
		double pip = ((double)rand() / (double)RAND_MAX * (2 - 0) + 0)-1;
		ys[i + 1] = y[i + 1] + p * pip;
	}
	ofstream out;
	out.open("y.txt");
	for (int i = 0; i < N; i++)
	{
		out.setf(ios_base::fixed);
		out <<  y[i] << endl;
	}
	out.close();
	out.open("ys.txt");
	for (int i = 0; i < N; i++)
	{
		out.setf(ios_base::fixed);
		out << ys[i] << endl;
	}
	out.close();
	system("pause");
}


