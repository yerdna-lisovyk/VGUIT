#pragma once
#include <math.h>
void ArrayFillingA_4(double(&a)[4][4], const double y[300], const int i0, const double u[300])
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
		a[2][0] += y[i - 1] * y[i - 3];
	}
	for (int i = i0; i < 300; i++)//A41
	{
		a[3][0] += y[i - 1] * u[i - 1];
	}

	for (int i = i0; i < 300; i++)//A12
	{
		a[0][1] += y[i - 1] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//A22
	{
		a[1][1] += pow(y[i - 2], 2.);
	}
	for (int i = i0; i < 300; i++)//A32
	{
		a[2][1] += y[i - 3] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//A42
	{
		a[3][1] += y[i - 2] * u[i - 1];
	}


	for (int i = i0; i < 300; i++)//A13
	{
		a[0][2] += y[i - 1] * y[i - 3];
	}
	for (int i = i0; i < 300; i++)//A23
	{
		a[1][2] += y[i - 3] * y[i - 2];
	}
	for (int i = i0; i < 300; i++)//A33
	{
		a[2][2] += pow(y[i - 3], 2.);
	}
	for (int i = i0; i < 300; i++)//A43
	{
		a[3][2] += y[i - 3] * u[i - 1];
	}


	for (int i = i0; i < 300; i++)//A14
	{
		a[0][3] += y[i - 1] * u[i - 1];
	}
	for (int i = i0; i < 300; i++)//A24
	{
		a[1][3] += y[i - 2] * u[i - 1];
	}
	for (int i = i0; i < 300; i++)//A34
	{
		a[2][3] += u[i - 1] * y[i - 3];
	}
	for (int i = i0; i < 300; i++)//A44
	{
		a[3][3] += pow(u[i - 1], 2.);
	}
}
void ArrayFillingP_4(double(&b)[4], const double y[300], const int i0, const double u[300])
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
		b[2] += y[i] * y[i - 3];
	}
	for (int i = i0; i < 300; i++)//B4
	{
		b[3] += y[i] * u[i - 1];
	}
}

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