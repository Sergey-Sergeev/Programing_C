#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

Объявить массив данных типа double размером 3 на 3. Ввести с консоли его значения, вывести на консоль сумму его элементов, расположенных на главной диагонали и сумму элементов, расположенных на  побочной диагонали.
	Объявить массив данных типа int размером 2 на 2. Ввести с консоли его значе-ния, вывести на консоль квадрат данной матрицы.

*/

void** malloc2DArray(int lenX, int lenY, size_t elementSize);
void free2DArray(void** array, int lenX);
void printArrayLF(int lenX, int lenY, double** array);
void printArrayD(int lenX, int lenY, int** array);
void setArrayLF(int lenX, int lenY, double** array);
void setArrayD(int lenX, int lenY, int** array);

const int LF_ARRAY_LEN_X = 3;
const int LF_ARRAY_LEN_Y = 3;
int D_ARRAY_LEN_X = 2;
int D_ARRAY_LEN_Y = 2;

int main(int argc, char* argv[]) {

	double** array = (double**)malloc2DArray(LF_ARRAY_LEN_X, LF_ARRAY_LEN_Y, sizeof(double));
	setArrayLF(LF_ARRAY_LEN_X, LF_ARRAY_LEN_Y, array);
	printArrayLF(LF_ARRAY_LEN_X, LF_ARRAY_LEN_Y, array);

	double dgMain = 0;
	double dgSide = 0;

	for (int i = 0; i < 3; i++)
		dgMain = dgMain + array[i][i];

	dgSide = array[0][2] + array[1][1] + array[2][0];

	free2DArray(array, LF_ARRAY_LEN_X);

	printf("main diagonal sum = %lf\n", dgMain);
	printf("side diagonal sum = %lf\n", dgSide);

	int** dArray = (int**)malloc2DArray(D_ARRAY_LEN_X, D_ARRAY_LEN_Y, sizeof(int));
	int** dArray_copy = (int**)malloc2DArray(D_ARRAY_LEN_X, D_ARRAY_LEN_Y, sizeof(int));

	setArrayD(D_ARRAY_LEN_X, D_ARRAY_LEN_Y, dArray);
	printArrayD(D_ARRAY_LEN_X, D_ARRAY_LEN_Y, dArray);

	for (int x = 0; x < D_ARRAY_LEN_X; x++)
	{
		for (int y = 0; y < D_ARRAY_LEN_Y; y++)
		{
			int val = 0;

			for (int k = 0; k < D_ARRAY_LEN_Y; k++)
			{
				val += dArray[x][k] * dArray[k][y];
			}

			dArray_copy[x][y] = val;
		}
	}

	printf("digital array in square:\n");
	printArrayD(D_ARRAY_LEN_X, D_ARRAY_LEN_Y, dArray_copy);
	free2DArray(dArray_copy, D_ARRAY_LEN_X);
	free2DArray(dArray, D_ARRAY_LEN_X);

	return 0;
}

void** malloc2DArray(int lenX, int lenY, size_t elementSize)
{
	void** ptr = (void**)malloc(sizeof(int) * lenX);
	for (int i = 0; i < lenX; i++)
	{
		ptr[i] = (void*)malloc(elementSize * lenY);
	}
	return ptr;
}

void free2DArray(void** array, int lenX)
{
	for (int i = 0; i < lenX; i++)
	{
		free(array[i]);
	}

	array = NULL;
}

void printArrayD(int lenX, int lenY, int** array)
{
	for (int x = 0; x < lenX; x++)
	{
		for (int y = 0; y < lenY; y++)
		{
			printf("[%d]", array[x][y]);
		}

		printf("\n");
	}
}

void setArrayD(int lenX, int lenY, int** array)
{
	for (int x = 0; x < lenX; x++)
	{
		for (int y = 0; y < lenY; y++)
		{
			printf("enter array value with index [%d][%d]: ", x, y);
			scanf("%d", &array[x][y]);
		}
	}
}

void setArrayLF(int lenX, int lenY, double** array)
{
	for (int x = 0; x < lenX; x++)
	{
		for (int y = 0; y < lenY; y++)
		{
			printf("enter array value with index [%d][%d]: ", x, y);
			scanf("%lf", &array[x][y]);
		}
	}
}

void printArrayLF(int lenX, int lenY, double** array)
{
	for (int x = 0; x < lenX; x++)
	{
		for (int y = 0; y < lenY; y++)
		{
			printf("[%lf]", array[x][y]);
		}

		printf("\n");
	}
}


