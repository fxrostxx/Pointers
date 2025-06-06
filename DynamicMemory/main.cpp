#include <iostream>
using namespace std;

void FillArr(int arr[], const int n);
void PrintArr(int arr[], const int n);

int main()
{
	setlocale(LC_ALL, "rus");

	int n;
	cout << "¬ведите размер массива: ";
	cin >> n;
	int* arr = new int[n];

	FillArr(arr, n);
	PrintArr(arr, n);

	return 0;
}

void FillArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		*(arr + i) = rand() % 100;
	}
}
void PrintArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}