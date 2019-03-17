#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <queue>

using namespace std;

#define MAX 100010

int n, m, root = 0;
bool marked[MAX];
int entryTime[MAX], bestTime[MAX], parent[MAX];

vector< vector< int > > list;
set< pair < int, int > > bridges;

void findBridges(int start, int dfsCount)
{
	marked[start] = true;
	bestTime[start] = entryTime[start] = dfsCount;

	for (int i = 0; i < list[start].size(); i++)
	{
		int child = list[start][i];

		if (!marked[child])
		{
			parent[child] = start;
			findBridges(child, dfsCount + 1);
			bestTime[start] = min(bestTime[start], bestTime[child]);

			if (bestTime[child] > entryTime[start])
				bridges.insert(make_pair(start, child));

			if (bestTime[child] >= entryTime[start])
			{
				if (root != start)
					cout << start << endl;

				else
					if (list[start].size() > 1) cout << start << endl;
			}
		}
		
		else if (child != parent[start])
			bestTime[start] = min(bestTime[start], entryTime[child]);
	}
}

int main()
{
	cin >> n >> m;
	list.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		list[x].push_back(y);
		list[y].push_back(x);
	}

	root = 1;
	findBridges(1, 0);
}