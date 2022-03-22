#include <iostream>
#include <time.h>

using namespace std;
void BubbleSort(int tab[], int size);
void SelectionSort(int tab[], int size);
void InsertSort(int tab[], int size);
void CountingSort(int tab[], int size, int max);
void SitoEratostenesa(int max);
bool IsPrime(int num);
void PrintTab(int tab[], int size);
void Swap(int* a, int* b);
void SzukanieLidera(int tab[], int size);
void RandTab(int tab[], int size);


int main()
{
	int tab[10] = { 1,2,3,4,5,6,7 };
	CountingSort(tab, 10, 7);
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

void SelectionSort(int tab[], int size)
{
	int min;
	for (int i = 0; i < size - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (tab[j] < tab[min]) min = j;
		}
		Swap(&tab[i], &tab[min]);
	}
}

void InsertSort(int tab[], int size)
{
	int key;
	for (int i = 1; i < size; i++)
	{
		key = i;
		while (tab[key] < tab[key - 1] && key > 0)
		{
			Swap(&tab[key], &tab[key - 1]);
			key--;
		}
	}
}

void CountingSort(int tab[], int size, int max)
{
	int* countTab = new int[max + 1]{0};
	for (int i = 0; i < size; i++)
	{
		countTab[tab[i]]++;
	}
	for (int i = 1; i <= size; i++)
	{
		countTab[i] += countTab[i - 1];
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
		tab[i] = rand() % 50 + 1;
	}
}

void SitoEratostenesa(int max)
{
	bool* tab = new bool[max + 2];
	for (int i = 0; i < max; i++)
	{
		tab[i] = true;
	}

	for (int i = 2; i <= max; i++)
	{
		if (tab[i] == false) continue;
		if (IsPrime(i))
		{
			for (int j = i * 2; j <= max; j+=i)
			{
				tab[j] = false;
			}
		}
	}

	for (int i = 2; i <= max; i++)
	{
		if (tab[i] == true)
		{
			cout << i << endl;
		}
	}
}

bool IsPrime(int num)
{
	for (int i = 2; i <= num / 2; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}
	return true;
}

bool LinearSearch(int tab[], int size, int value)
{
	for (int i = 0; i < size; i++)
	{
		if (tab[i] == value) return true;
	}
	return false;
}

bool SzukanieZWartownikiem(int tab[], int size, int value)
{
	tab[size] = value;
	int i;
	for (i = 0; i <= size; i++)
	{
		if (tab[i] == value) break;
	}
	if (i < size) return true;
	return false;
}

void SzukanieLidera(int tab[], int size)
{
	int count = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (tab[j] == tab[i]) count++;
		}
		if (count > size / 2)
		{
			cout << "Liderem jest: " << tab[i] << endl;
			break;
		}
		count = 0;
	}
	cout << "Zbior nie ma lidera\n";
}