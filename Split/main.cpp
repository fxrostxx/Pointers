#include <iostream>
using namespace std;

void FillArr(int arr[], const int n);
void PrintArr(int arr[], const int n);

int main()
{
	setlocale(LC_ALL, "rus");
	srand(time(NULL));

	int n = 10;
	int* arr = new int[n];

	FillArr(arr, n);
	cout << "Исходный массив: " << endl;
	PrintArr(arr, n);

	int evenSize{ 0 };

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] % 2 == 0) ++evenSize;
	}

	int oddSize = n - evenSize;

	int* even = new int[evenSize];
	int* odd = new int[oddSize];
	int evenCount{ 0 }, oddCount{ 0 };

	for (int i = 0; i < n; ++i)
	{
		if (arr[i] % 2 == 0) even[evenCount++] = arr[i];
		else odd[oddCount++] = arr[i];
	}

	cout << "Массив четных чисел: " << endl;
	PrintArr(even, evenSize);
	cout << "Массив нечетных чисел: " << endl;
	PrintArr(odd, oddSize);

	delete[] arr;
	delete[] even;
	delete[] odd;

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
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << "\t";
	}
	cout << endl;
}