#include "PopRowBack.h"

template<typename T>
T** PopRowBack(T** arr, int& rows)
{
	delete[] arr[rows - 1];

	return PopBack(arr, rows);
}