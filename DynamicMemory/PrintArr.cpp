#include "PrintArr.h"

template<typename T>
void PrintArr(T arr[], const int n)
{
	for (int i = 0; i < n; ++i) cout << arr[i] << "\t";
	cout << endl;
}

template<typename T>
void PrintArr(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; ++i) PrintArr(arr[i], cols);
}