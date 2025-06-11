#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void FillArr(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillArr(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void PrintArr(int arr[], const int n);
void PrintArr(int** arr, const int rows, const int cols);
int* PushBack(int arr[], int &n, const int value);
int* PushFront(int arr[], int &n, const int value);
int* Insert(int arr[], int& n, const int index, const int value);
int* PopBack(int arr[], int& n);
int* PopFront(int arr[], int& n);
int* Erase(int arr[], int& n, const int index);

int** PushRowBack(int** arr, int &rows, int cols);
void PushColBack(int** arr, const int rows, int& cols);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef DYNAMIC_MEMORY_1
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
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_2

	int rows, cols;

	cout << "Введите количество строк: ";
	cin >> rows;
	cout << "Введите количество столбцов: ";
	cin >> cols;

	int** arr = new int* [rows];

	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new int[cols];
	}

	FillArr(arr, rows, cols);

	PrintArr(arr, rows, cols);

	cout << "Добавление строки в конец:" << endl;

	arr = PushRowBack(arr, rows, cols);

	FillArr(arr[rows - 1], cols, 100, 1000);

	PrintArr(arr, rows, cols);

	cout << "Добавление столбца в конец:" << endl;

	PushColBack(arr, rows, cols);

	for (int i = 0; i < rows; ++i) arr[i][cols - 1] = rand() % 900 + 100;

	PrintArr(arr, rows, cols);

	for (int i = 0; i < rows; ++i)
	{
		delete[] arr[i];
	}

	delete[] arr;

#endif // DYNAMIC_MEMORY_2

	return 0;
}

void FillArr(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; ++i) *(arr + i) = rand() % (maxRand - minRand) + minRand;
}
void FillArr(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void PrintArr(int arr[], const int n)
{
	for (int i = 0; i < n; ++i) cout << arr[i] << "\t";
	cout << endl;
}
void PrintArr(int** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
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

int** PushRowBack(int** arr, int& rows, int cols)
{
	int** newArr = new int* [rows + 1];

	for (int i = 0; i < rows; ++i)
	{
		newArr[i] = arr[i];
	}

	delete[] arr;

	newArr[rows] = new int[cols] {};

	++rows;

	return newArr;
}

void PushColBack(int** arr, const int rows, int& cols)
{
	for (int i = 0; i < rows; ++i)
	{
		int* temp = new int[cols + 1] {};

		for (int j = 0; j < cols; ++j) temp[j] = arr[i][j];

		delete[] arr[i];

		arr[i] = temp;
	}

	++cols;
}