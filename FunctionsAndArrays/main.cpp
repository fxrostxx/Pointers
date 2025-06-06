#include <iostream>
using namespace std;

void FillArr(int arr[], const int n);
void PrintArr(int arr[], const int n);

int main()
{
	setlocale(LC_ALL, "rus");

	const int n = 5;
	int arr[n];

	cout << typeid(arr).name() << endl;

	FillArr(arr, n);
	PrintArr(arr, n);

	return 0;
}

void FillArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		arr[i] = rand() % 100;
	}
}
void PrintArr(int arr[], const int n)
{
	cout << typeid(arr).name() << endl;
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}