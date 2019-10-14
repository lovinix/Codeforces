#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, ansv[3][3][100'010];
lli cost[3][100'010], ans = LLONG_MAX, cur;
vector<int> adj[100'010];

void recv(int u, int c, int p);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 1; j <= N; ++j)
			cin >> cost[i][j];
	}
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		if(adj[u].size()>2 || adj[v].size()>2)
		{
			cout << -1;
			return 0;
		}
	}
	int idx, pp, p, nxt, ppc, pc;
	int ansi, ansj;
	for(int i=1;i<=N;++i)
	{
		if (adj[i].size() == 1) { idx = i; break; }
	}
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			if (i == j) continue;
			pp = idx; ppc = i;
			p = adj[idx][0]; pc = j;
			ansv[i][j][pp] = i;
			ansv[i][j][p] = j;
			cur = cost[i][pp] + cost[j][p];
			while (adj[p].size() > 1)
			{
				nxt = (adj[p][0] == pp ? adj[p][1] : adj[p][0]);
				int nc = 3 - ppc - pc;
				cur += cost[nc][nxt];
				ansv[i][j][nxt] = nc;
				pp = p; p = nxt; ppc = pc; pc = nc;
			}
			if (cur < ans)
			{
				ans = cur;
				ansi = i; ansj = j;
			}
		}
	}
	cout << ans << "\n";
	for (int i = 1; i <= N; ++i)
	{
		cout << ansv[ansi][ansj][i] + 1 << " ";
	}
}
