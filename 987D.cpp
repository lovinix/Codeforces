#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, K, S, g[100'010], vst[100'010][101];
vector<int> adj[100'010];
queue<pii> q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> S;
	for (int i = 1; i <= N; ++i)
		cin >> g[i];
	for (int i = 1; i <= M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}

	for (int i = 1; i <= K; ++i)
	{
		while (q.size()) q.pop();
		for (int u = 1; u <= N; ++u) 
			if (g[u] == i) { q.emplace(u, 0); vst[u][i] = 1; }
		while (!q.empty())
		{
			auto [u, d] = q.front();
			q.pop();
			for (auto& v : adj[u])
			{
				if (vst[v][i]) continue;
				vst[v][i] = d + 1;
				q.emplace(v, d + 1);
			}
		}
	}

	for (int i = 1; i <= N; ++i)
	{
		sort(vst[i] + 1, vst[i] + K + 1);
		int ans = 0;
		for (int j = 1; j <= S; ++j) ans += vst[i][j];
		cout << ans - 1 << " ";
	}
}

