// 2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>

using namespace std;
void ArrayFillingA(double(&a)[3][3], const double y[300], const int i0, const double u[300])
{
	for (int i = i0; i < 300; i++)//A11
	{
		a[0][0] += pow(y[i - 1], 2.);
	}
	for (int i = i0; i < 300; i++)//A21
	{
		a[1][0] += y[i - 1] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//A31
	{
		a[2][0] += y[i - 1] * u[i - 1];
	}

	for (int i = i0; i < 300; i++)//A12
	{
		a[0][1] += y[i - 1] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//A22
	{
		a[1][1] += pow(y[i - 1], 2.);
	}
	for (int i = i0; i < 300; i++)//A32
	{
		a[2][1] += y[i - 2] * u[i - 1];
	}

	for (int i = i0; i < 300; i++)//A13
	{
		a[0][2] += y[i - 1] * u[i - 1];
	}
	for (int i = i0; i < 300; i++)//A23
	{
		a[1][2] += y[i - 2] * u[i - 1];
	}
	for (int i = i0; i < 300; i++)//A33
	{
		a[2][2] += pow(u[i - 1], 2.);
	}
}
void ArrayFillingP(double(&b)[3], const double y[300], const int i0, const double u[300])
{
	for (int i = i0; i < 300; i++)//B1
	{
		b[0] += y[i] * y[i - 1];
	}
	for (int i = i0; i < 300; i++)//B2
	{
		b[1] += y[i] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//B3
	{
		b[2] += y[i] * u[i - 1];
	}
}

double determinant(double matrix[3][3])
{
	double a11 = matrix[0][0];
	double a12 = matrix[0][1];
	double a13 = matrix[0][2];
	double a21 = matrix[1][0];
	double a22 = matrix[1][1];
	double a23 = matrix[1][2];
	double a31 = matrix[2][0];
	double a32 = matrix[2][1];
	double a33 = matrix[2][2];

	return (a11 * a22 * a33) + (a12 * a23 * a31) + (a13 * a21 * a32) -
		(a13 * a22 * a31) - (a11 * a23 * a32) - (a12 * a21 * a33);
}

double determinantX1(double coefMatrix[3][3], double constTermsMatrix[3])
{
	double a12 = coefMatrix[0][1];
	double a13 = coefMatrix[0][2];
	double a22 = coefMatrix[1][1];
	double a23 = coefMatrix[1][2];
	double a32 = coefMatrix[2][1];
	double a33 = coefMatrix[2][2];
	double c1 = constTermsMatrix[0];
	double c2 = constTermsMatrix[1];
	double c3 = constTermsMatrix[2];

	return (c1 * a22 * a33) + (a12 * a23 * c3) + (a13 * c2 * a32) -
		(a13 * a22 * c3) - (c1 * a23 * a32) - (a12 * c2 * a33);
}

double determinantX2(double coefMatrix[3][3], double constTermsMatrix[3])
{
	double a11 = coefMatrix[0][0];
	double a13 = coefMatrix[0][2];
	double a21 = coefMatrix[1][0];
	double a23 = coefMatrix[1][2];
	double a31 = coefMatrix[2][0];
	double a33 = coefMatrix[2][2];
	double c1 = constTermsMatrix[0];
	double c2 = constTermsMatrix[1];
	double c3 = constTermsMatrix[2];

	return (a11 * c2 * a33) + (c1 * a23 * a31) + (a13 * a21 * c3) -
		(a13 * c2 * a31) - (a11 * a23 * c3) - (c1 * a21 * a33);
}

double determinantX3(double coefMatrix[3][3], double constTermsMatrix[3])
{
	double a11 = coefMatrix[0][0];
	double a12 = coefMatrix[0][1];
	double a21 = coefMatrix[1][0];
	double a22 = coefMatrix[1][1];
	double a31 = coefMatrix[2][0];
	double a32 = coefMatrix[2][1];
	double c1 = constTermsMatrix[0];
	double c2 = constTermsMatrix[1];
	double c3 = constTermsMatrix[2];

	return (a11 * a22 * c3) + (a12 * c2 * a31) + (c1 * a21 * a32) -
		(c1 * a22 * a31) - (a11 * c2 * a32) - (a12 * a21 * c3);
}

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
	double a1 = (T11 * T0 + 2 * T22 - pow(T0, 2.)) / (T22 + T11 * T0);
	double a2 = -T22 / (T22 + T11 * T0);
	double b = (k * pow(T0, 2.)) / (T22 + T11 * T0);

	double u[N] = { 0 };
	double y[N] = { 0 };
	double ys[N] = { 0 };

	int i0 = maxi(2., d + 1);
	for (int i = i0; i < N - 1; i++)
	{
		u[i] = 1;
		int x = i - d;
		y[i + 1] = a1 * y[i] + a2 * y[i - 1] + b * u[x];
		double pip = ((double)rand() / (double)RAND_MAX * (2 - 0) + 0)-1;
		ys[i + 1] = y[i + 1] + p * pip;
	}
	ofstream out;
	out.open("y.txt");
	for(int i=0;i<N;i++)
	{
		out<< y[i]<<endl;
	}
	out.close();
	out.open("ys.txt");
	for(int i=0;i<N;i++)
	{
		out<< ys[i]<<endl;
	}
	out.close();
	ifstream file("ys.txt");
	for (int i = 0; i < N; i++)
	{
		file >> ys[i];
	}
	double y_2[N] = { 0 };

	double a[3][3] = { 0 };
	double pa[3] = { 0 };
	ArrayFillingA(a, ys, i0, u);
	ArrayFillingP(pa, ys, i0, u);

	double delta = determinant(a);
	double delta_A = determinantX1(a, pa);
	double delta_B = determinantX2(a, pa);
	double delta_C = determinantX3(a, pa);

	double newA1 = delta_A / delta;
	double newA2 = delta_B / delta;
	double newb = delta_C / delta;

	for (int i = i0; i < N-1; i++)
	{
		int x = i - d;
		y_2[i+1] = newA1 * y_2[i] + newA2 * y_2[i-1] + newb * u[x];
	}
	ofstream Fout;
	Fout.open("y_2.txt");
	for (int i = 0; i < N; i++)
	{
		Fout << y_2[i] << endl;
	}
	Fout.close();
}

