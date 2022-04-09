// 2.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <ctime>
#include "Determinant.h"
#include "ArrayFilling.h"

using namespace std;


void tmpMatrix(double(&a)[4][4], double(&b)[4], double(&tmp)[4][4], int pj)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tmp[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		tmp[i][pj] = b[i];
	}
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
		//double pip = ((double)rand() / (double)RAND_MAX * (2 - 0) + 0)-1;
		//ys[i + 1] = y[i + 1] + p * pip;
	}
	/*ofstream out;
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
	out.close();*/
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

	for (int i = i0; i < N - 1; i++)
	{
		int x = i - d;
		y_2[i + 1] = newA1 * y_2[i] + newA2 * y_2[i - 1] + newb * u[x];
	}
	ofstream Fout;
	Fout.open("y_2.txt");
	for (int i = 0; i < N; i++)
	{
		Fout << y_2[i] << endl;
	}
	Fout.close();
	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += ys[i];
	}
	sum = sum / N;
	double Sy_2 = 0;
	for (int i = 0; i < N; i++)
	{
		Sy_2 += pow((ys[i] - sum), 2.);

	}
	Sy_2 = Sy_2 / (N - 1);
	double S_ost = 0;
	for (int i = 0; i < N; i++)
	{
		S_ost += pow((y_2[i] - ys[i]), 2.);

	}
	S_ost = S_ost / (N - 1 - 3);
	double F = Sy_2 / S_ost;
	cout << "F_2 = " << F << endl;


	//3 порядок
	double a_4[4][4] = { 0 };
	double tmp[4][4] = { 0 };
	ArrayFillingA_4(a_4, y, i0, u,1);
	double b_4[4] = { 0 };
	ArrayFillingP_4(b_4, y, i0, u,1);
	delta = Determenant_4(a_4);

	tmpMatrix(a_4, b_4, tmp, 0);
	delta_A = Determenant_4(tmp);

	tmpMatrix(a_4, b_4, tmp, 1);
	delta_B = Determenant_4(tmp);

	tmpMatrix(a_4, b_4, tmp, 2);
	delta_C = Determenant_4(tmp);

	tmpMatrix(a_4, b_4, tmp, 3);
	double delta_D = Determenant_4(tmp);

	newA1 = delta_A / delta;
	newA2 = delta_B / delta;
	double newA3 = delta_C / delta;
	newb = delta_D / delta;
	double y_3[N] = { 0 };
	for (int i = i0; i < N - 1; i++)
	{
		int x = i - d;
		y_3[i + 1] = newA1 * y_3[i] + newA2 * y_3[i - 1] + newA3 * y_3[i - 2] + newb * u[x];
	}
	Fout.open("y_3.txt");
	for (int i = 0; i < N; i++)
	{
		Fout << y_3[i] << endl;
	}
	Fout.close();
	S_ost = 0;
	for (int i = 0; i < N; i++)
	{
		S_ost += pow((y_3[i] - ys[i]), 2.);

	}
	S_ost = S_ost / (N - 1 - 3);
	F = Sy_2 / S_ost;
	cout << "F_3 = " << F << endl;
	system("pause");
}

