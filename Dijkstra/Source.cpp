#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

#define INF INT_MAX
#define SIZE 100010

int dis[SIZE];
vector< pair<int, int> > list[SIZE];

class comparator
{
	public:

		bool operator()(pair<int, int> &child1, pair<int, int> &child2)
		{
			return child1.second > child2.second;
		}
};

void dijkstra(int start)
{
	for (int i = 0; i < SIZE; i++)
	{
		dis[i] = INF;
	}

	dis[start] = 0;
	priority_queue<pair<int, int>, vector<pair<int, int>>, comparator> pq;
	pq.push(make_pair(start, dis[start]));

	while (!pq.empty())
	{
		pair<int, int> head = pq.top();
		pq.pop();
		int headVertex = head.first;
		int headWeight = head.second;
		int childVertex, childWeight;

		for (int i = 0; i < list[headVertex].size(); i++)
		{
			childVertex = list[headVertex][i].first;
			childWeight = list[headVertex][i].second;

			if (childWeight + headWeight < dis[childVertex])
			{
				dis[childVertex] = childWeight + headWeight;
				pq.push(make_pair(childVertex , dis[childVertex]));
			}
		}
	}
}

int main()
{
	int n, m, x, y, w;
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> x >> y >> w;
		list[x].push_back(make_pair(y, w));
		list[y].push_back(make_pair(x, w));
	}

	dijkstra(1);

	for (int i = 1; i <= n ; i++)
	{
		cout << i << " " << dis[i] << endl;
	}

	return 0;
}
