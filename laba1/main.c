#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float calcRoot(float D, float a, float b, int sign);

int main(int argc, char* argv[]) {

	while (1)
	{
		printf("enter a, b, c values:\n");

		float a, b, c, x1, x2, d;

		scanf("%f", &a);
		scanf("%f", &b);
		scanf("%f", &c);

		d = powf(b, 2) - 4 * a * c;

		printf("d = %f\n", d);

		if (d < 0)
		{
			printf("There is not roots.\n");
		}
		else if (d == 0)
		{
			printf("Have only one root\n");
			x1 = calcRoot(d, a, b, 1);
			printf("x1 = %f\n", x1);
		}
		else
		{
			printf("Have two roots\n");
			x1 = calcRoot(d, a, b, 1);
			x2 = calcRoot(d, a, b, -1);
			printf("x1 = %f\n", x1);
			printf("x2 = %f\n", x2);
		}

		printf("\nDo you want to find roots again? (y/n): ");
		bool continueWork = true;
		char ch;
		while (1)
		{
			ch = getch();
			if (ch == 'y') break;			
			else if (ch == 'n')
			{
				continueWork = false;
				break;
			}
		}

		printf("%c", ch);

		if (!continueWork)	break;
		else printf("\n\n");
	}

	return 0;
}

float calcRoot(float D, float a, float b, int sign)
{
	return (-b + (sign * sqrt(D))) / (2 * a);
}

