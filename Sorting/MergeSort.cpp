#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define INF 10000000010

long long n;

vector <long long> myList;

void merge(long long start, long long mid, long long end)
{
	long long a = 0, b = 0;

	vector <long long> temp;
	vector <long long> A;
	vector <long long> B;

	for (long long i = start; i < mid + 1; i++)
	{
		A.push_back(myList[i]);
	}

	A.push_back(INF);

	for (long long i = mid + 1; i <= end; i++)
	{
		B.push_back(myList[i]);
	}

	B.push_back(INF);

	for (long long i = start; i <= end; i++)
	{
		if (A[a] > B[b])
		{
			temp.push_back(B[b]);
			b++;
		}

		else
		{
			temp.push_back(A[a]);
			a++;
		}
	}

	for (long long i = 0; i < temp.size(); i++)
	{
		myList[start + i] = temp[i];
	}
}

void inversion(long long start, long long end)
{
	if (start < end)
	{
		long long mid = ((start + end) / 2);
		inversion(start, mid);
		inversion(mid + 1, end);
		merge(start, mid, end);
	}
}

int main()
{
	cout << "How many items do you want to sort ? ";
	cin >> n;
	cout << "Please enter your items : " << endl;

	for (long long i = 0; i < n; i++)
	{
		long long x;
		cin >> x;
		myList.push_back(x);
	}

	inversion(0, n - 1);

	for (int i = 0; i < n; i++)
	{
		cout << myList[i] << " ";
	}
}