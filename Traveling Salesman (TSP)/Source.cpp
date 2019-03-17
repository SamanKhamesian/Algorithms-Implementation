#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

#define MAX_SIZE 17

int n, dist[MAX_SIZE][MAX_SIZE], dp[MAX_SIZE][1 << MAX_SIZE];

int tsp(int pos, int bitmask) 
{
	if (bitmask == (1 << n) - 1)
		return dist[pos][0];

	else if (dp[pos][bitmask] != -1)
		return dp[pos][bitmask];

	else
	{
		int ans = 2000000000;

		for (int nxt = 0; nxt < n; nxt++)
			if (nxt != pos && !(bitmask & (1 << nxt)))
				ans = min(ans, dist[pos][nxt] + tsp(nxt, bitmask | (1 << nxt)));
			
		return dp[pos][bitmask] = ans;
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < (n * (n - 1)) / 2; i++)
	{
		int x, y, w;
		cin >> x >> y >> w;
		dist[x][y] = dist[y][x] = w;
	}

	memset(dp, -1, sizeof dp);
	printf("The shortest route has length %d\n", tsp(0, 1));

	return 0;
}
