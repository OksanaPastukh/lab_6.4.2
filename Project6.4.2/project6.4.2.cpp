// Lab_6.4.2.
#include<iostream>
#include<iomanip>
#include<time.h>
using namespace std;

void Random(int* p, int n, int Low, int High, int i)
{

	p[i] = rand() % (High - Low + 1) + Low;
	if (i < n - 1)
		Random(p, n, Low, High, i + 1);
}
void Print(int* p, int n, int i)
{
	cout << setw(3) << p[i] << " ";
	if (i < n - 1)
		Print(p, n, i + 1);
	else
		cout << endl;
}
int Count(int* p, int n, int i)
{
	if (i < n)
	{
		return ((p[i] == 0) ? 1 : 0) + Count(p, n, i + 1);
	}
	else
		return 0;
}
void find_min_index(int* p, int n, int i, int* min_value,int* min_index)
{
	if (i < n - 1)
	{
		find_min_index(p, n, i + 1, min_value, min_index);
		if (p[i] < *min_value)
		{
			*min_value = p[i];
			*min_index = i;
		}
	}
	else
	{
		*min_value = p[i];
		*min_index = i;
	}
		
}
int Sum(int* p, int n,  int i)
{
	if (i < n)
		return p[i] + Sum(p, n,  i + 1);
	else
		return 0;

}


void Sort(int* p, int n, int i) // метод обміну (бульбашки)
{
	int k = 0; // показник, чи були обміни
	for (int j = 0; j < n - i; j++) // номер поточного елемента
		if (abs(p[j]) > abs(p[j + 1])) // якщо порушено порядок
		{ // - обмін елементів місцями
			int tmp = p[j];
			p[j] = p[j + 1];
			p[j + 1] = tmp;
			k = 1;
		}
	if (k == 0) // якщо обмінів - не було,
		return; // то припиняємо процес
	if (i < n - 1) // i - лічильник ітерацій
		Sort(p, n, i + 1); // перехід до наступної ітерації
}
int main()
{
	srand((unsigned)time(NULL));

	int n;
	cout << "n = "; cin >> n;

	int* p = new  int[n];
	int Low;
	int High;
	cout << "Low = "; cin >> Low;
	cout << "High = "; cin >> High;
	Random(p, n, Low, High, 0);
	Print(p, n, 0);
	cout << "Count = " << Count(p, n,0) << endl;
	int min_value = 0;
	int min_index = 0;
	find_min_index(p, n, 0, &min_value, &min_index);
	cout << "S = " << Sum(p, n, min_index +1) << endl;
	Sort(p, n, 1);
	Print(p, n, 0);
	delete[] p;
	return 0;
}