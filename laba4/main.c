#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#include "Triangle.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
* 
Написать функции, вычисляющие периметр и площадь треугольника по значениям длин трёх его сторон.
Разместить их в отдельном модуле (отличном от того, где располагается функция main( )).
Ввести с консоли значения длин сторон треугольника (с проверкой на корректность неравенства треугольника)
и выдать на консоль вычисленные с помощью написанных функций значения его периметра и площади.

*/

int main(int argc, char* argv[]) {
	while (1)
	{
		char input[11];
		double A, B, C;
		printf("Enter sides of triangle:\n");
		printf("A: ");
		scanf("%10s", &input);
		A = atof(input);

		printf("B: ");
		scanf("%10s", &input);
		B = atof(input);

		printf("C: ");
		scanf("%10s", &input);
		C = atof(input);

		if (!IsTriangleExist(A, B, C))
		{
			printf("Triangle with these parameters doesn't exist.\n");
			continue;
		}

		double P = CalcTrianglePerimetr(A, B, C);
		double S = CalcTriangleSquare(A, B, C);

		printf("Triangle's perimeter is [ %lf ],\nTriangle's square is [ %lf ]", P, S);
		
		break;
	}

	return 0;
}
