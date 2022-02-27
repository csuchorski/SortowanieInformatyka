#include <iostream>

using namespace std;
void BubbleSort(int tab[]);
void PrintTab(int tab[]);
void Swap(int* a, int* b);

int main()
{
	int tab[10]{ 13,28,1,7,6,5,4,1,2,10 };
	PrintTab(tab);
	BubbleSort(tab);
	PrintTab(tab);
	return 0;
}

void BubbleSort(int tab[]) 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (tab[j] > tab[j + 1])
			{
				Swap(&tab[j], &tab[j + 1]);
			}
		}
	}
}


void PrintTab(int tab[])
{
	for (int i = 0; i < 10; i++)
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