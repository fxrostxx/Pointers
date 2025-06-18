#include "PopBack.h"

template<typename T>
T* PopBack(T arr[], int& n)
{
	T* newArr = new T[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	return newArr;
}