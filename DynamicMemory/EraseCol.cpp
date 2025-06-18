#include "EraseCol.h"

template<typename T>
void EraseCol(T** arr, const int rows, int& cols, const int index)
{
	if (index == 0) PopColFront(arr, rows, cols);
	else if (index == cols - 1) PopColBack(arr, rows, cols);
	else
	{
		int tempCols;

		for (int i = 0; i < rows; ++i)
		{
			tempCols = cols;
			arr[i] = Erase(arr[i], tempCols, index);
		}

		--cols;
	}
}