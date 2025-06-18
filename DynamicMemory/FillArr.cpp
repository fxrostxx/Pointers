#include "FillArr.h"

void FillArr(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; ++i) *(arr + i) = rand() % (maxRand - minRand) + minRand;
}
void FillArr(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < n; ++i)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}

void FillArr(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; ++i) FillArr(arr[i], cols, minRand, maxRand);
}
void FillArr(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; ++i) FillArr(arr[i], cols, minRand, maxRand);
}