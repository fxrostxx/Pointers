#include "PopFront.h"

template<typename T>
T* PopFront(T arr[], int& n)
{
	T* newArr = new T[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i + 1];

	delete[] arr;

	return newArr;
}