#include "PushRowFront.h"

template<typename T>
T** PushRowFront(T** arr, int& rows, const int cols)
{
	T* newRow = new T[cols];

	return PushFront(arr, rows, newRow);
}