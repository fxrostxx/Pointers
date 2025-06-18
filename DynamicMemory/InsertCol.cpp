#include "InsertCol.h"

template<typename T>
void InsertCol(T** arr, const int rows, int& cols, const int index)
{
	if (index == 0) PushColFront(arr, rows, cols);
	else if (index == cols) PushColBack(arr, rows, cols);
	else
	{
		int tempCols;

		for (int i = 0; i < rows; ++i)
		{
			tempCols = cols;

			arr[i] = Insert(arr[i], tempCols, index, T());
		}

		++cols;
	}
}