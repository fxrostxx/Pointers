#include <iostream>
using namespace std;

void FillArr(int arr[], const int n);
void PrintArr(int arr[], const int n);
int* PushBack(int arr[], int &n, const int value);
int* PushFront(int arr[], int &n, const int value);
int* Insert(int arr[], int& n, const int index, const int value);
int* PopBack(int arr[], int& n);
int* PopFront(int arr[], int& n);
int* Erase(int arr[], int& n, const int index);

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
	cout << "Введите значение элемента добавляемого в конец: ";
	cin >> value;

	arr = PushBack(arr, n, value);

	PrintArr(arr, n);

	cout << "Введите значение элемента добавляемого в начало: ";
	cin >> value;

	arr = PushFront(arr, n, value);

	PrintArr(arr, n);

	arr = PopBack(arr, n);

	cout << "Удален последний элемент: " << endl;
	PrintArr(arr, n);

	arr = PopFront(arr, n);

	cout << "Удален первый элемент: " << endl;
	PrintArr(arr, n);

	int index;

	cout << "Введите индекс добавляемого элемента: ";
	cin >> index;
	cout << "Введите значение добавляемого элемента: ";
	cin >> value;

	arr = Insert(arr, n, index, value);

	PrintArr(arr, n);

	cout << "Введите индекс удаляемого элемента: ";
	cin >> index;

	arr = Erase(arr, n, index);

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

int* Insert(int arr[], int& n, const int index, const int value)
{
	if (index == n) return PushBack(arr, n, value);
	else if (index == 0) return PushFront(arr, n, value);
	else
	{
		int* newArr = new int[++n];
		for (int i = 0; i < index; ++i) newArr[i] = arr[i];
		newArr[index] = value;
		for (int i = index + 1; i < n; ++i) newArr[i] = arr[i - 1];

		delete[] arr;

		return newArr;
	}
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

int* Erase(int arr[], int& n, const int index)
{
	if (index == n - 1) return PopBack(arr, n);
	else if (index == 0) return PopFront(arr, n);
	else
	{
		int* newArr = new int[n - 1];
		for (int i = 0; i < index; ++i) newArr[i] = arr[i];
		for (int i = index + 1; i < n; ++i) newArr[i - 1] = arr[i];

		delete[] arr;

		--n;

		return newArr;
	}
}