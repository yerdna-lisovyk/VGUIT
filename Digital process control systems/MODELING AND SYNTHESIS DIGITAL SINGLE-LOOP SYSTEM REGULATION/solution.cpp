


#include <iostream>
#include <math.h>

#include <fstream>
void Unstoc(double(&y)[300], double(&u)[300], double(&yz)[300], const int i0, const int d, double a1, double a2, double b, double q0, double q1)
{
	for (int i = 0; i < 300; i++)
	{
		yz[i] = 0;
		u[i] = 0;
		y[i] = 0;
	}

	for (int i = i0; i < 300 - 1; i++)
	{
		yz[i] = 1;
		u[i] = u[i - 1] + q0 * (yz[i] - y[i]) + q1 * (yz[i - 1] - y[i - 1]);
		y[i + 1] = a1 * y[i] + a2 * y[i - 1] + b * u[i - d];
	}
}
double S_unctoc(const double y[300], const double yz[300])
{
	double sum = 0;
	for (int i = 0; i < 300 - 1; i++)
	{
		sum += pow(yz[i] - y[i], 2.);
	}
	return sum;
}
int main()
{
	const double k1 = 1.5, k2 = 0.5;
	const double eps = 0.01;
	double delta = pow(10., -10.);
	const int N = 300;
	const double a1 = 1.936719, a2 = -0.9375, b = 0.003125;
	const double T0 = 0.1;
	double y[N] = { 0 }, yz[N] = { 0 }, u[N] = { 0 };

	const int d = 5;
	const int i0 = d + 1;
	double q0 = 0.1, q1 = -0.1;
	long double sq = 0;

	double dsdq0 = 0;
	double dsdq0_1 = 0;

	double dsdq1 = 0;
	double dsdq1_1 = 0;

	bool first = 0;
	double H0 = 1. / 3., H1 = 1. / 3.;
	int k = 0;
	do {
		double S = 0, Sq1 = 0, Sq2 = 0;
		Unstoc(y, u, yz, i0, d, a1, a2, b, q0, q1);
		S = S_unctoc(y, yz);

		q0 += delta;
		Unstoc(y, u, yz, i0, d, a1, a2, b, q0, q1);
		Sq1 = S_unctoc(y, yz);

		q0 -= delta;
		q1 += delta;
		Unstoc(y, u, yz, i0, d, a1, a2, b, q0, q1);
		Sq2 = S_unctoc(y, yz);
		q1 -= delta;

		dsdq0_1 = dsdq0;
		dsdq1_1 = dsdq1;

		dsdq0 = (Sq1 - S) / delta;
		dsdq1 = (Sq2 - S) / delta;

		sq = sqrt(dsdq0 * dsdq0 + dsdq1 * dsdq1);

		if (first != 0)
		{
			if (dsdq0 * dsdq0_1 > 0)
				H0 = H0 * k1;
			else
				H0 = H0 * k2;

			if (dsdq1 * dsdq1_1 > 0)
				H1 = H1 * k1;
			else
				H1 = H1 * k2;
		}
		q0 -= H0 * dsdq0 / sq;
		q1 -= H1 * dsdq1 / sq;
		first = 1;
	} while (sq > eps);
	std::cout << k++ << std::endl;
	std::cout << "q0=" << q0 << std::endl;
	std::cout << "q1=" << q1 << std::endl;
	std::cout << "H1=" << H0 << std::endl;
	std::cout << "H2=" << H1 << std::endl;
	std::cout << "sq=" << sq << std::endl << std::endl;
	std::ofstream out;
	out.open("y.txt");
	for (int i = 0; i < N; i++)
	{
		out << y[i] << std::endl;
	}
	out.close();
	out.open("yz.txt");
	for (int i = 0; i < N; i++)
	{
		out << yz[i] << std::endl;
	}
	out.close();
	system("pause");
	return 0;
}

