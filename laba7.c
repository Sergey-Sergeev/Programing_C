#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <locale.h> 
#include <string.h>
#include <stdarg.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*
Объявить тип-структуру humen, включающую имя человека, фамилию и год рождения.
Объявить два массива из четырёх элементов типа humen.
Ввести с консоли или из файла элементы одного массива и построить на их основе другой,
упорядочив эле-менты по годам рождения. Вывести результат.
*/

#define HUMEN_MAX_NAME_LEN	1000
#define COUNT_OF_HUMEN	4

struct Humen
{
	char* name;
	char* surname;
	int birthday;
};

const char* concatenate(const char* strs, ...);
int sortHumenByBirthday(struct Humen humen1, struct Humen humen2);
void displayHumenArray(int len, struct Humen* arr);


int laba7(int argc, char* argv[]) {
	setlocale(LC_ALL, "Russian");

	struct Humen* arr = (struct Humen*)malloc(sizeof(struct Humen) * COUNT_OF_HUMEN);
	struct Humen* sorted = (struct Humen*)malloc(sizeof(struct Humen) * COUNT_OF_HUMEN);

	int i;
	for (i = 0; i < COUNT_OF_HUMEN; i++)
	{
		char name[HUMEN_MAX_NAME_LEN];
		char surname[HUMEN_MAX_NAME_LEN];
		int birthday;

		char value[10];
		sprintf(value, "%d", HUMEN_MAX_NAME_LEN);
		const char* str = concatenate("%", value, "s", NULL);

		printf("Enter the name of the person:  ");
		scanf(str, name);

		printf("Enter the surname of the person:  ");
		scanf(str, surname);

		free(str);

		printf("Enter the birthday of the person:  ");
		scanf("%d", &birthday);

		int nameLen = strlen(name);
		int surnameLen = strlen(surname);

		arr[i].name = (char*)malloc(sizeof(char) * (nameLen + 1));
		arr[i].surname = (char*)malloc(sizeof(char) * (surnameLen + 1));
		arr[i].name[nameLen] = 0;
		arr[i].surname[surnameLen] = 0;
		arr[i].name = strcpy(arr[i].name, name);
		arr[i].surname = strcpy(arr[i].surname, surname);

		sorted[i].name = (char*)malloc(sizeof(char) * (nameLen + 1));
		sorted[i].surname = (char*)malloc(sizeof(char) * (surnameLen + 1));
		sorted[i].name[nameLen] = 0;
		sorted[i].surname[surnameLen] = 0;
		sorted[i].name = strcpy(sorted[i].name, name);
		sorted[i].surname = strcpy(sorted[i].surname, surname);

		arr[i].birthday = birthday;
		sorted[i].birthday = birthday;
	}

	qsort(sorted, COUNT_OF_HUMEN, sizeof(struct Humen), sortHumenByBirthday);

	printf("Array not sorted:\n");
	displayHumenArray(COUNT_OF_HUMEN, arr);
	printf("Array sorted:\n");
	displayHumenArray(COUNT_OF_HUMEN, sorted);

	free(arr);
	free(sorted);

	return 0;
}

void displayHumenArray(int len, struct Humen* arr)
{
	printf("\n>------------------------------<\n");
	int i;
	for (i = 0; i < len; i++)
	{
		printf("\nHumen [ %d ]\n", i + 1);
		printf("\t[Name:  %s]\n", arr[i].name);
		printf("\t[Surname:  %s]\n", arr[i].surname);
		printf("\t[Day of born:  %d]\n", arr[i].birthday);
	}
	printf("\n>------------------------------<\n");
}

int sortHumenByBirthday(struct Humen humen1, struct Humen humen2)
{
	return humen1.birthday - humen2.birthday;
}

/*
*
* Function that concatenate strings in one,
* last parameter must be NULL
*/
const char* concatenate(const char* strs, ...)
{
	va_list allstrs;
	int index = 0;
	char* curstr = strs;
	int allLen = strlen(strs);

	va_start(allstrs, strs);

	while ((curstr = va_arg(allstrs, char*)) != NULL)
		allLen += strlen(curstr);

	va_end(allstrs);

	char* result = (char*)malloc(sizeof(char) * (allLen + 1));

	va_start(allstrs, strs);
	curstr = strs;
	do
	{
		for (; *curstr != '\0'; )
		{
			result[index++] = *curstr;
			curstr++;
		}
	} while ((curstr = va_arg(allstrs, char*)) != NULL);

	result[index] = '\0';

	va_end(allstrs);
	return result;
}