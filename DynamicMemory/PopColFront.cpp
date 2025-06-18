#include "PopColFront.h"

template<typename T>
void PopColFront(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PopFront(arr[i], tempCols);
	}

	--cols;
}