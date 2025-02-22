#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "ArrayManager.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

Разместить в динамической памяти 2 массива – 2 матрицы размерностью n на n с элементами типа double
(значения n и элементы массивов ввести с консоли). А также ввести с консоли знак операции: '+', '-' или '*'.
Написать функцию, вычисляющую сум-му, разность или произведение данных матриц (их передать по указателю)
и возвра-щающую указатель на массив-результат. Разместить эту функцию в отдельном модуле (отличном от того,
где располагается функция main()). Выдать на консоль значения по-лученного вектора.

*/

const char const OPERATIONS[4] = {'+', '-', '*', '\0'};
bool IsOperationValid(char op, char* array);

int main(int argc, char* argv[]) {
	while (1)
	{
		long N = 0;

		printf("Enter matrixes' size: ");
		scanf("%ld", &N);

		if (N < 1)
		{
			printf("Not valid value!");
			return 0;
		}

		double** mA = CreateMatrix(N);
		double** mB = CreateMatrix(N);

		printf("Set first matrix,\n");
		SetMatrix(mA, N);
		printf("Set second matrix,\n");
		SetMatrix(mB, N);

		PrintMatrix(mA, N);
		PrintMatrix(mB, N);

		char op = 0;

		while (1)
		{
			op = getch();

			if (IsOperationValid(op, OPERATIONS))
				break;
			else printf("Invalid operation!\n");
		}

		double** res = NULL;
		switch (op)
		{
		case '+':
			res = SumMatrixes(mA, mB, N);
			break;
		case '-':
			res = SubMatrixes(mA, mB, N);
			break;
		case '*':
			res = MulMatrixes(mA, mB, N);
			break;
		}

		printf("\n");
		PrintMatrix(res, N);

		DeleteMatrix(res, N);
		DeleteMatrix(mA, N);
		DeleteMatrix(mB, N);
	}

	return 0;
}

bool IsOperationValid(char op, char* array)
{
	int i = 0;
	while (array[i] != '\0')
		if (array[i++] == op)
			return true;

	return false;
}
