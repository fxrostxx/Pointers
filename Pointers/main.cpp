#include <iostream>
using namespace std;

//#define POINTER_BASICS

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef POINTER_BASICS
	int a = 2;
	int* pa = &a;

	cout << a << endl;
	cout << &a << endl;
	cout << pa << endl;
	cout << *pa << endl;
#endif

	const int n = 5;
	int arr[n] = { 3,5,8,13,21 };

	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; ++i)
	{
		cout << *(arr + i) << "\t";
	}
	cout << endl;

	return 0;
}