#include <iostream>
#include <algorithm>

using namespace std;

void bubble_sort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = n - 1; j > i ; j--)
		{
			if (A[j] < A[j - 1])
			{
				swap(A[j], A[j - 1]);
			}
		}
	}
}

int main()
{
	int n;

	cout << "How many items do you want to sort ? ";
	cin >> n;
	cout << "Please enter your items : " << endl;

	int* A = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}

	bubble_sort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}