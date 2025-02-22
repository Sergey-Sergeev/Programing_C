#pragma once


double** CreateMatrix(int N);
void DeleteMatrix(double** matrix, int N);
void PrintMatrix(double** matrix, int N);

void SetMatrix(double** matrix, int N);
double** SumMatrixes(double** mA, double** mB, int N);
double** MulMatrixes(double** mA, double** mB, int N);
double** SubMatrixes(double** mA, double** mB, int N);