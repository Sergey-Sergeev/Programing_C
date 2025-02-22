#include "ArrayManager.h"
#include <stdio.h>
#include <stdlib.h>

double** CreateMatrix(int N)
{
	double** matrix = (double**)malloc(sizeof(double*) * N);

	for (int i = 0; i < N; i++)
	{
		matrix[i] = (double*)malloc(sizeof(double) * N);
	}

	return matrix;
}

void DeleteMatrix(double** matrix, int N)
{
	for (int i = 0; i < N; i++)
	{
		free(matrix[i]);
	}

	free(matrix);
}

void PrintMatrix(double** matrix, int N)
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			printf("[%lf]", matrix[x][y]);
		}
		printf("\n");
	}
}

void SetMatrix(double** matrix, int N)
{
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			printf("Enter value in [%d][%d]: ", x, y);
			scanf_s("%lf", &matrix[x][y]);
		}
	}
}

double** SumMatrixes(double** mA, double** mB, int N)
{
	double** res = CreateMatrix(N);

	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			res[x][y] = mA[x][y] + mB[x][y];
		}
	}	

	return res;
}

double** MulMatrixes(double** mA, double** mB, int N)
{
	double** res = CreateMatrix(N);
	
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			int val = 0;

			for (int k = 0; k < N; k++)
			{
				val += mA[x][k] * mB[k][y];
			}

			res[x][y] = val;
		}
	}

	return res;
}

double** SubMatrixes(double** mA, double** mB, int N)
{
	double** res = CreateMatrix(N);
	for (int x = 0; x < N; x++)
	{
		for (int y = 0; y < N; y++)
		{
			res[x][y] = mA[x][y] - mB[x][y];
		}
	}

	return res;
}
