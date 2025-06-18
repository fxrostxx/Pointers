#include "PushColBack.h"

template<typename T>
void PushColBack(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PushBack(arr[i], tempCols, T());
	}

	++cols;
}