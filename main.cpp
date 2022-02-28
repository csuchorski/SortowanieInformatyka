#include <iostream>
#include <time.h>

using namespace std;
void BubbleSort(int tab[], int size);
void PrintTab(int tab[], int size);
void Swap(int* a, int* b);
void RandTab(int tab[], int size);

int main()
{
	const int size = 10;
	int* tab = new int[size];
	RandTab(tab, size);
	PrintTab(tab, size);
	BubbleSort(tab, size);
	PrintTab(tab, size);	

	return 0;
}

void BubbleSort(int tab[], int size) 
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				Swap(&tab[j], &tab[j + 1]);
			}
		}
	}
}

void PrintTab(int tab[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << tab[i] << endl;
	}
	cout << "___\n";
}

void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void RandTab(int tab[], int size)
{
	srand(time(NULL));
	for (int i = 0; i < size; i++)
	{
		tab[i] = rand() % 20 + 1;
	}
}