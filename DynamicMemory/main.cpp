#include <iostream>
using namespace std;

void FillArr(int arr[], const int n);
void PrintArr(int arr[], const int n);
int* PushBack(int arr[], int &n, const int value);
int* PushFront(int arr[], int &n, const int value);
int* PopBack(int arr[], int& n);
int* PopFront(int arr[], int& n);

int main()
{
	setlocale(LC_ALL, "rus");

	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	int* arr = new int[n];

	FillArr(arr, n);
	PrintArr(arr, n);

	int value;
	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	arr = PushBack(arr, n, value);

	PrintArr(arr, n);

	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	arr = PushFront(arr, n, value);

	PrintArr(arr, n);

	arr = PopBack(arr, n);

	cout << "Удален последний элемент: " << endl;
	PrintArr(arr, n);

	arr = PopFront(arr, n);

	cout << "Удален первый элемент: " << endl;
	PrintArr(arr, n);

	delete[] arr;

	return 0;
}

void FillArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i) *(arr + i) = rand() % 100;
}
void PrintArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i) cout << arr[i] << "\t";
	cout << endl;
}

int* PushBack(int arr[], int &n, const int value)
{
	int* newArr = new int[n + 1];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	newArr[n] = value;

	++n;

	return newArr;
}

int* PushFront(int arr[], int& n, const int value)
{
	int* newArr = new int[n + 1];

	for (int i = 0; i < n; ++i) newArr[i + 1] = arr[i];

	delete[] arr;

	newArr[0] = value;

	++n;

	return newArr;
}

int* PopBack(int arr[], int& n)
{
	int* newArr = new int[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	return newArr;
}

int* PopFront(int arr[], int& n)
{
	int* newArr = new int[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i + 1];

	delete[] arr;

	return newArr;
}