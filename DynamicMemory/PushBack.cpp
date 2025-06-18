#include "PushBack.h"

template<typename T>
T* PushBack(T arr[], int& n, const T value)
{
	T* newArr = new T[n + 1];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	newArr[n] = value;

	++n;

	return newArr;
}