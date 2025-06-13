#include <iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

void FillArr(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillArr(double arr[], const int n, int minRand = 0, int maxRand = 100);
template<typename T> void PrintArr(T arr[], const int n);
template<typename T> T* PushBack(T arr[], int &n, const T value);
template<typename T> T* PushFront(T arr[], int &n, const T value);
template<typename T> T* Insert(T arr[], int& n, const int index, const T value);
template<typename T> T* PopBack(T arr[], int& n);
template<typename T> T* PopFront(T arr[], int& n);
template<typename T> T* Erase(T arr[], int& n, const int index);

void FillArr(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillArr(double** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
template<typename T> void Allocate(T**& arr, const int rows, const int cols);
template<typename T> void Clear(T**& arr, const int rows, const int cols);
template<typename T> void PrintArr(T** arr, const int rows, const int cols);
template<typename T> T** PushRowBack(T** arr, int &rows, const int cols);
template<typename T> T** PushRowFront(T** arr, int &rows, const int cols);
template<typename T> T** InsertRow(T** arr, int& rows, const int cols, const int index);
template<typename T> T** PopRowBack(T** arr, int& rows);
template<typename T> T** PopRowFront(T** arr, int& rows);
template<typename T> T** EraseRow(T** arr, int& rows, const int index);
template<typename T> void PushColBack(T** arr, const int rows, int& cols);
template<typename T> void PushColFront(T** arr, const int rows, int& cols);
template<typename T> void InsertCol(T** arr, const int rows, int& cols, const int index);
template<typename T> void PopColBack(T** arr, const int rows, int& cols);
template<typename T> void PopColFront(T** arr, const int rows, int& cols);
template<typename T> void EraseCol(T** arr, const int rows, int& cols, const int index);

//#define DYNAMIC_MEMORY_1
#define DYNAMIC_MEMORY_2

typedef double DataType;

int main()
{
	setlocale(LC_ALL, "rus");

#ifdef DYNAMIC_MEMORY_1
	int n;
	cout << "Введите размер массива: ";
	cin >> n;
	DataType *arr = new DataType[n];

	FillArr(arr, n);
	PrintArr(arr, n);

	DataType value;
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

	DataType** arr;

	Allocate(arr, rows, cols);

	FillArr(arr, rows, cols);

	PrintArr(arr, rows, cols);

	cout << "Добавление строки в конец:" << endl;
	arr = PushRowBack(arr, rows, cols);
	FillArr(arr[rows - 1], cols, 100, 1000);
	PrintArr(arr, rows, cols);

	cout << "Добавление строки в начало:" << endl;
	arr = PushRowFront(arr, rows, cols);
	FillArr(arr[0], cols, 100, 1000);
	PrintArr(arr, rows, cols);

	int index;

	cout << "Введите индекс добавляемой строки: ";
	cin >> index;
	arr = InsertRow(arr, rows, cols, index);
	FillArr(arr[index], cols, 100, 1000);
	PrintArr(arr, rows, cols);

	cout << "Удаление последней строки:" << endl;
	arr = PopRowBack(arr, rows);
	PrintArr(arr, rows, cols);

	cout << "Удаление первой строки:" << endl;
	arr = PopRowFront(arr, rows);
	PrintArr(arr, rows, cols);

	cout << "Введите индекс удаляемой строки: ";
	cin >> index;
	arr = EraseRow(arr, rows, index);
	PrintArr(arr, rows, cols);

	cout << "Добавление столбца в конец:" << endl;
	PushColBack(arr, rows, cols);
	for (int i = 0; i < rows; ++i) arr[i][cols - 1] = rand() % 900 + 100;
	PrintArr(arr, rows, cols);

	cout << "Добавление столбца в начало:" << endl;
	PushColFront(arr, rows, cols);
	for (int i = 0; i < rows; ++i) arr[i][0] = rand() % 900 + 100;
	PrintArr(arr, rows, cols);

	cout << "Введите индекс добавляемого столбца: ";
	cin >> index;
	InsertCol(arr, rows, cols, index);
	for (int i = 0; i < rows; ++i) arr[i][index] = rand() % 900 + 100;
	PrintArr(arr, rows, cols);

	cout << "Удаление последнего столбца:" << endl;
	PopColBack(arr, rows, cols);
	PrintArr(arr, rows, cols);

	cout << "Удаление первого столбца:" << endl;
	PopColFront(arr, rows, cols);
	PrintArr(arr, rows, cols);

	cout << "Введите индекс удаляемого столбца: ";
	cin >> index;
	EraseCol(arr, rows, cols, index);
	PrintArr(arr, rows, cols);

	Clear(arr, rows, cols);

#endif // DYNAMIC_MEMORY_2

	return 0;
}

void FillArr(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; ++i) *(arr + i) = rand() % (maxRand - minRand) + minRand;
}
void FillArr(double arr[], const int n, int minRand, int maxRand)
{
	minRand *= 100;
	maxRand *= 100;

	for (int i = 0; i < n; ++i)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand;
		arr[i] /= 100;
	}
}
template<typename T>
void PrintArr(T arr[], const int n)
{
	for (int i = 0; i < n; ++i) cout << arr[i] << "\t";
	cout << endl;
}

template<typename T>
T* PushBack(T arr[], int &n, const T value)
{
	T* newArr = new T[n + 1];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	newArr[n] = value;

	++n;

	return newArr;
}

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

template<typename T>
T* Insert(T arr[], int& n, const int index, const T value)
{
	if (index == n) return PushBack(arr, n, value);
	else if (index == 0) return PushFront(arr, n, value);
	else
	{
		T* newArr = new T[++n];
		for (int i = 0; i < index; ++i) newArr[i] = arr[i];
		newArr[index] = value;
		for (int i = index + 1; i < n; ++i) newArr[i] = arr[i - 1];

		delete[] arr;

		return newArr;
	}
}

template<typename T>
T* PopBack(T arr[], int& n)
{
	T* newArr = new T[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i];

	delete[] arr;

	return newArr;
}

template<typename T>
T* PopFront(T arr[], int& n)
{
	T* newArr = new T[--n];

	for (int i = 0; i < n; ++i) newArr[i] = arr[i + 1];

	delete[] arr;

	return newArr;
}

template<typename T>
T* Erase(T arr[], int& n, const int index)
{
	if (index == n - 1) return PopBack(arr, n);
	else if (index == 0) return PopFront(arr, n);
	else
	{
		T* newArr = new T[n - 1];
		for (int i = 0; i < index; ++i) newArr[i] = arr[i];
		for (int i = index + 1; i < n; ++i) newArr[i - 1] = arr[i];

		delete[] arr;

		--n;

		return newArr;
	}
}

void FillArr(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; ++i) FillArr(arr[i], cols, minRand, maxRand);
}
void FillArr(double** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; ++i) FillArr(arr[i], cols, minRand, maxRand);
}
template<typename T>
void Allocate(T**& arr, const int rows, const int cols)
{
	arr = new T* [rows];

	for (int i = 0; i < rows; ++i)
	{
		arr[i] = new T[cols];
	}
}
template<typename T>
void Clear(T**& arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; ++i) delete[] arr[i];

	delete[] arr;

	arr = nullptr;
}
template<typename T>
void PrintArr(T** arr, const int rows, const int cols)
{
	for (int i = 0; i < rows; ++i) PrintArr(arr[i], cols);
}

template<typename T>
T** PushRowBack(T** arr, int& rows, const int cols)
{
	T* newRow = new T[cols]{};

	return PushBack(arr, rows, newRow);
}

template<typename T>
T** PushRowFront(T** arr, int& rows, const int cols)
{
	T* newRow = new T[cols];

	return PushFront(arr, rows, newRow);
}

template<typename T>
T** InsertRow(T** arr, int& rows, const int cols, const int index)
{
	if (index == 0) return PushRowFront(arr, rows, cols);
	else if (index == rows) return PushRowBack(arr, rows, cols);
	else
	{
		T* newRow = new T[cols]{};

		return Insert(arr, rows, index, newRow);
	}
}

template<typename T>
T** PopRowBack(T** arr, int& rows)
{
	return PopBack(arr, rows);
}

template<typename T>
T** PopRowFront(T** arr, int& rows)
{
	return PopFront(arr, rows);
}

template<typename T>
T** EraseRow(T** arr, int& rows, const int index)
{
	if (index == 0) return PopRowFront(arr, rows);
	else if (index == rows - 1) return PopRowBack(arr, rows);
	else return Erase(arr, rows, index);
}

template<typename T>
void PushColBack(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PushBack(arr[i], tempCols, T(0));
	}

	++cols;
}

template<typename T>
void PushColFront(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PushFront(arr[i], tempCols, T(0));
	}

	++cols;
}

template<typename T>
void InsertCol(T** arr, const int rows, int& cols, const int index)
{
	if (index == 0) PushColFront(arr, rows, cols);
	else if (index == cols) PushColBack(arr, rows, cols);
	else
	{
		int tempCols;

		for (int i = 0; i < rows; ++i)
		{
			tempCols = cols;

			arr[i] = Insert(arr[i], tempCols, index, T(0));
		}

		++cols;
	}
}

template<typename T>
void PopColBack(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PopBack(arr[i], tempCols);
	}

	--cols;
}

template<typename T>
void PopColFront(T** arr, const int rows, int& cols)
{
	int tempCols;

	for (int i = 0; i < rows; ++i)
	{
		tempCols = cols;

		arr[i] = PopFront(arr[i], tempCols);
	}

	--cols;
}

template<typename T>
void EraseCol(T** arr, const int rows, int& cols, const int index)
{
	if (index == 0) PopColFront(arr, rows, cols);
	else if (index == cols - 1) PopColBack(arr, rows, cols);
	else
	{
		int tempCols;

		for (int i = 0; i < rows; ++i)
		{
			tempCols = cols;
			arr[i] = Erase(arr[i], tempCols, index);
		}

		--cols;
	}
}