#pragma once
#include <math.h>
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
double Determenant_4(double(&a)[4][4])
{
	double  sum = 0;
	int k = 0;
	for (int p = 0; p < 4; p++)
	{
		double matrix[3][3] = { 0 };
		int l = 0;
		for (int i = 0; i < 4; i++)
		{
			if (k != i)
			{
				for (int j = 1; j < 4; j++)
				{
					matrix[l][j - 1] = a[i][j];
				}
				l++;
			}
		}
		k++;
		sum += pow((-1.),(k+1.)) * determinant(matrix);
	}
	return sum;
}