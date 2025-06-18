#include "PopColBack.h"

template<typename T>
void PopColBack(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PopBack(arr[i], tempCols);
	}

	--cols;
}