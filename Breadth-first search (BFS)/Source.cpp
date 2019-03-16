#include <iostream>
#include <queue>
#include <climits>
#include <vector>

using namespace std;

#define INF INT_MAX

int n, m, v, w;

vector<vector<int>> list;

vector<bool> marked;

vector<int> parent;

vector<int> dist;

queue<int> bfsq;

void bfs(int start)
{
	for (int i = 0; i <= n ; i++)
	{
		dist[i] = INF;

		parent[i] = -1;
	}

	marked[start] = true;

	dist[start] = 0;

	bfsq.push(start);

	while (!bfsq.empty())
	{
		int temp = bfsq.front();

		bfsq.pop();

		for (int i = 0; i < list[temp].size(); i++)
		{
			if (!marked[list[temp][i]])
			{
				bfsq.push(list[temp][i]);

				dist[list[temp][i]] = dist[temp] + 1;

				marked[list[temp][i]] = true;

				parent[list[temp][i]] = temp;
			}
		}
	}
}

int main()
{
	cin >> n >> m;

	list.resize(n + 1);

	dist.resize(n + 1);

	marked.resize(n + 1);

	parent.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> v >> w;

		list[v].push_back(w);

		list[w].push_back(v);
	}

	// Find all shortest paths from node 1 to others

	bfs(1);
}