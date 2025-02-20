#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

//#include "laba2.c"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Ввести с консоли строку символов произвольной длины (до 80 символов).
По-менять в ней все маленькие символы ‘a’ и ‘b’ на заглавные и вывести на консоль полу-ченную строку.


*/


const int MAX_STR_LEN = 81;

int main(int argc, char* argv[]) {

	char* str = (char*)malloc(MAX_STR_LEN * sizeof(char));
	for (int i = 0; i < MAX_STR_LEN; i++)
		str[i] = '_';
	str[MAX_STR_LEN - 1] = '\0';

	scanf("%80s", str);

	for (int i = 0; i < MAX_STR_LEN; i++)
	{
		if (str[i] == 'a')
			str[i] = 'A';
		else if (str[i] == 'b')
			str[i] = 'B';
		
		printf("%c", str[i]);
	}

	free(str);

	return 0;
}
