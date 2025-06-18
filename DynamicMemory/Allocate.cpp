#include "Allocate.h"

template<typename T>
void Allocate(T**& arr, const int rows, const int cols)
{
	arr = new T * [rows];

	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new T[cols];
	}
}