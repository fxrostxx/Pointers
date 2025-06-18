#include "PushFront.h"

template<typename T>
T* PushFront(T arr[], int& n, const T value)
{
	T* newArr = new T[n + 1];

	for (int i = 0; i < n; ++i) newArr[i + 1] = arr[i];

	delete[] arr;

	newArr[0] = value;

	++n;

	return newArr;
}