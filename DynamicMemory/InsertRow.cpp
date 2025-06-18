#include "InsertRow.h"

template<typename T>
T** InsertRow(T** arr, int& rows, const int cols, const int index)
{
	if (index == 0) return PushRowFront(arr, rows, cols);
	else if (index == rows) return PushRowBack(arr, rows, cols);
	else
	{
		T* newRow = new T[cols]{};

		return Insert(arr, rows, index, newRow);
	}
}