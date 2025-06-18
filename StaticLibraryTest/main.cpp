#include "stdafx.h"
#include "FillArr.h"
#include "PrintArr.h"
#include "PushBack.h"
#include "PushFront.h"
#include "Insert.h"
#include "PopBack.h"
#include "PopFront.h"
#include "Erase.h"
#include "Allocate.h"
#include "Clear.h"
#include "PushRowBack.h"
#include "PushRowFront.h"
#include "InsertRow.h"
#include "PopRowBack.h"
#include "PopRowFront.h"
#include "EraseRow.h"
#include "PushColBack.h"
#include "PushColFront.h"
#include "InsertCol.h"
#include "PopColBack.h"
#include "PopColFront.h"
#include "EraseCol.h"


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