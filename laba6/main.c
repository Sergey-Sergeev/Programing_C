#define _CRT_SECURE_NO_WARNINGS		// Чтобы компилятор не ругался на безопастность функции scanf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <locale.h> 
#include <uchar.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

/*

Создать текстовый файл с записями следующего вида:
Иванов Петр Сергеевич 1975
Сидоров Николай Андреевич 1981
….
Воробьянинов Ипполит Матвеевич 1978

	Прочитать данные из этого файла и записать в другой только те строки, которые относятся к родившимся позднее 1980 года.


*/

#define MAX_NAME_LENGTH		1000
int dataFilter = 1980;

int main(int argc, char* argv[]) {
	FILE* FIN, * FOUT;
	char path[200];

	setlocale(LC_ALL, "Russian");
	printf("This program will sotred by data [%d]\n", dataFilter);

	printf("Write file path with data: ");
	scanf("%200s", &path);
	OemToCharA(path, path);
	FIN = fopen(path, "r");

	printf("Write file path where will be written sorted data: ");
	scanf("%200s", &path);
	OemToCharA(path, path);
	FOUT = fopen(path, "w");


	if (FIN == NULL)
	{
		printf("Cant open file for data.");
		exit(1);
	}

	if (FOUT == NULL)
	{
		printf("Cant open file for sorted data.");
		exit(2);
	}

	int number;
	char firstName[MAX_NAME_LENGTH];
	char middleName[MAX_NAME_LENGTH];
	char lastName[MAX_NAME_LENGTH];
	int year;

	while (fscanf(FIN, "%d. %s %s %s %d", &number, lastName, firstName, middleName, &year) == 5) {
		if (year > dataFilter)
		{
			fprintf(FOUT, "%d. %s %s %s %d\n", number, lastName, firstName, middleName, year);
		}
	}

	fclose(FIN);
	fclose(FOUT);

	return 0;
}
