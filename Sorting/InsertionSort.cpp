#include <iostream>
#include <algorithm>

using namespace std;

void insertion_sort(int A[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int index = i;

		while (index > 0 && A[index] < A[index - 1])
		{
			swap(A[index], A[index - 1]);
			index--;
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

	insertion_sort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << " ";
	}
}