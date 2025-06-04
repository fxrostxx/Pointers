#include <iostream>
using namespace std;

void Exchange(int a, int b);

int main()
{
	setlocale(LC_ALL, "rus");

	int a = 2, b = 3;

	cout << a << "\t" << b << endl;
	
	Exchange(a, b);

	cout << a << "\t" << b << endl;

	return 0;
}

void Exchange(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}