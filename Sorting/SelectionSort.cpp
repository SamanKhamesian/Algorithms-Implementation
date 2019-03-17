#include <iostream>
#include <algorithm>

using namespace std;

void selection_sort(int A[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = A[i];
		int min_index = i;

		for (int j = i + 1; j < n ; j++)
		{
			if (A[j] < min)
			{
				min = A[j];
				min_index = j;
			}
		}

		swap(A[i], A[min_index]);
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

	selection_sort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}