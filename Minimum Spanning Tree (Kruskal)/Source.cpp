#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define SIZE 100010

int n, m;
int parent[SIZE], sz[SIZE];
vector< pair < pair< int, int >, int > > graph;

int findParent(int vertex)
{
	if (vertex == parent[vertex])
		return parent[vertex];

	else
		return parent[vertex] = findParent(parent[vertex]);
}

bool merge(pair<int, int> pairVertex)
{
	int x = pairVertex.first;
	int y = pairVertex.second;

	if (findParent(x) == findParent(y))
		return true;

	else
	{
		x = findParent(x);
		y = findParent(y);

		if (sz[x] < sz[y])
			swap(x, y);

		parent[y] = x;
		sz[x] += sz[y];

		return false;
	}
}

class comparator
{
public:

	bool operator()(pair<pair<int, int>, int> &child1, pair<pair<int, int>, int> &child2)
		return child1.second > child2.second;
};

priority_queue< pair< pair< int, int >, int >, vector< pair< pair< int, int >, int > >, comparator> pq;

int MST()
{
	int result = 0;

	while (!pq.empty())
	{
		pair<pair<int, int>, int> head = pq.top();

		if (!merge(make_pair(head.first.first, head.first.second)))
			result +=head.second;

		pq.pop();
	}

	return result;
}

void initialize()
{
	cin >> n >> m;
	graph.resize(m);
	memset(parent, 0, SIZE);

	for (int i = 1; i <= n; i++)
		parent[i] = i;

	for (int i = 0; i < m; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		graph[i] = (make_pair(make_pair(x, y), w));
		pq.push(graph[i]);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	initialize();
	cout << MST() << endl;
}