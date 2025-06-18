#include "Clear.h"

template<typename T>
void Clear(T**& arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; ++i) delete[] arr[i];

	delete[] arr;

	arr = nullptr;
}