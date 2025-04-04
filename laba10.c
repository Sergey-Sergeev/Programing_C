#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <windows.h>
#include <stdbool.h>
#include "list.h"


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Написать программу вычисления максимального числа из введенных пользователем в виде одной строки. 
Использовать для этого макрос (без функции), на вход которому подается массив чисел и их количество.
*/


#define MAX_BUFFER_LEN	10000
#define MAX_FORMAT_BUFFER_LEN	50



#define MAX_IN_ARR(arr, len, out) {int i_MAX_IN_ARR; out = arr[0]; for (i_MAX_IN_ARR = 0; i_MAX_IN_ARR < len; out = max(arr[i_MAX_IN_ARR], out), i_MAX_IN_ARR++);}

char* getNumbersInStr();
void strReplace(char** str, char from, char to);
char* deleteAllSpaces(char** str);
bool isCharExistIn(char ch, char* buff, int len);
char* addSpacesBeetwenNumbers(char** str);
double* parseNumbers(char* str, int* outLen);


int laba10() {
	setlocale(LC_ALL, "Russian");
	while (1)
	{
		printf("Enter numbers through common:  ");
		char* str = getNumbersInStr();
		int len = 0;
		double* nums = parseNumbers(str, &len);

		double maxValue = 0;

		MAX_IN_ARR(nums, len, maxValue);

		printf("Max value is [ %lf ]", maxValue);

		printf("\nTry again? (y/n):  ");
		char ch;
		while (1)
		{
			ch = getchar();
			if (ch == 'y')
				break;
			if (ch == 'n')
				goto exit1;
		}
	}

exit1:;
	return 0;
}


char* getNumbersInStr()
{
	char str[MAX_BUFFER_LEN];
	char format[MAX_FORMAT_BUFFER_LEN];

	sprintf(&format, " %c%d[^\n]", '%', MAX_BUFFER_LEN - 1);
	scanf(format, str);

	int len = strlen(str);
	char* res = (char*)malloc(sizeof(char) * (len + 1));
	res[len] = 0;
	res = strcpy(res, str);
	return res;
}

void strReplace(char** str, char from, char to)
{
	int len = strlen(*str);
	int i = 0;
	for (; i < len; i++)
		if ((*str)[i] == from)
			(*str)[i] = to;
}

char* deleteAllSpaces(char** str)
{
	int len = strlen(*str);
	int spacesCount = 0;
	int i = 0, j = 0;

	for (; i < len; i++)
		if ((*str)[i] == ' ')
			spacesCount++;

	int newLen = len - spacesCount;
	char* res = (char*)malloc(sizeof(char) * (newLen + 1));
	res[newLen] = 0;

	for (i = 0, j = 0; i < len; i++)
		if ((*str)[i] != ' ')
			res[j++] = (*str)[i];

	free(*str);

	return res;
}


double* parseNumbers(char* str, int* outLen)
{
	NODE* lv = NULL;
	char* valueStr;

	str = deleteAllSpaces(&str);

	valueStr = strtok(str, ",");

	while (valueStr != NULL)
	{
		double* val = (double*)malloc(sizeof(double));
		strReplace(&valueStr, '.', ',');
		*val = atof(valueStr);
		NODE* n = (NODE*)malloc(sizeof(NODE));
		n->data = (void*)val;

		add_node(&lv, n);
		valueStr = strtok(NULL, ",");
	}

	*outLen = list_len(&lv);

	if (*outLen == 0)
	{
		freeList(&lv);
		return NULL;
	}

	double* res = (double*)malloc(sizeof(double) * (*outLen));

	int i;
	for (i = 0; i < *outLen; i++)
		res[i] = *((double*)(get_node(&lv, i)->data));

	freeList(&lv);

	return res;
}


