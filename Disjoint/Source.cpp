#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define SIZE 100010

int parent[SIZE], sz[SIZE];

inline int findParent(int vertex)
{
	if (vertex == parent[vertex])
		return parent[vertex];

	else
		return parent[vertex] = findParent(parent[vertex]);
}

inline bool merge(pair<int, int> pairVertex)
{
	if (findParent(pairVertex.first) == findParent(pairVertex.second))
		return true;

	else
	{
		pairVertex.first = findParent(pairVertex.first);
		pairVertex.second = findParent(pairVertex.second);

		if (sz[pairVertex.first] < sz[pairVertex.second])
			swap(pairVertex.first, pairVertex.second);

		parent[pairVertex.second] = parent[pairVertex.first];
		sz[pairVertex.first] += sz[pairVertex.second];

		return false;
	}
}

int main()
{
	int n, m, x, y;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		sz[i] = 1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y;
		cout << merge(make_pair(x, y)) << endl;
	}

	for (int i = 1; i <= n; i++)
		cout << findParent(i) << endl;
}