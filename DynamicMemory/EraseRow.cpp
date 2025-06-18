#include "EraseRow.h"

template<typename T>
T** EraseRow(T** arr, int& rows, const int index)
{
	if (index == 0) return PopRowFront(arr, rows);
	else if (index == rows - 1) return PopRowBack(arr, rows);
	else
	{
		delete arr[index];

		return Erase(arr, rows, index);
	}
}