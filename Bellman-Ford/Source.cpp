#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

#define SIZE 100010
#define MAX 9999999

int dis[SIZE];
int parent[SIZE];
bool hasNegativeCycle = false;
vector< vector< pair< int, int > > > graph;

void bellmanFord(int n, int m, int start)
{
	static int pro = 0;

	for (int i = 0; i < SIZE; i++)
		dis[i] = MAX;

	dis[start] = 0;

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < graph[j].size(); k++)
			{
				pair<int, int> child = graph[j][k];
				dis[child.first] = min(dis[child.first], dis[j] + child.second);
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < graph[i].size(); j++)
		{
			pair<int, int> child = graph[i][j];

			if (dis[child.first] > dis[i] + child.second)           
				hasNegativeCycle = true;
		}
	}

	printf("Negative Cycle Exist? %s\n", hasNegativeCycle ? "Yes" : "No");
}

int main()
{
	int n, m, x, y, w;
	cin >> n >> m;
	graph.resize(n);

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		graph[x].push_back(make_pair(y, w));
		graph[y].push_back(make_pair(x, w));
	}

	bellmanFord(n, m, 1);

	for (int i = 0; i < n; i++)
		cout << i << " " << dis[i] << endl;
}