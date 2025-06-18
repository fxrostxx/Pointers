#include "PushRowBack.h"

template<typename T>
T** PushRowBack(T** arr, int& rows, const int cols)
{
	T* newRow = new T[cols]{};

	return PushBack(arr, rows, newRow);
}