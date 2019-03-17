#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, m, v, w;

vector< vector<int> > list;
vector<bool> marked;
vector<int> parent;
queue<int> bfsq;

void dfs(int current, int p)
{
	marked[current] = true;
	parent[current] = p;

	for (int i = 0; i < list[current].size(); i++)
	{
		if (!marked[list[current][i]])
		{
			dfs(list[current][i], current);
		}
	}
}

int main()
{
	cin >> n >> m;
	list.resize(n + 1);
	marked.resize(n + 1);
	parent.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> v >> w;
		list[v].push_back(w);
		list[w].push_back(v);
	}

	dfs(1, -1);
	
	for (int i = 0; i <= n; i++)
	{
		if (!marked[i])
		{
			cout << "disconnected" << endl;
			return 0;
		}
	}
}