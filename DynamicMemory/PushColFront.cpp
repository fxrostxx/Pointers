#include "PushColFront.h"

template<typename T>
void PushColFront(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PushFront(arr[i], tempCols, T());
	}

	++cols;
}