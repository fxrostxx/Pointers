#include "PopRowFront.h"

template<typename T>
T** PopRowFront(T** arr, int& rows)
{
	delete[] arr[0];

	return PopFront(arr, rows);
}