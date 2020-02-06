#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

int N, M, d[5010], p[5010], ans[5010];
vector<int> adj[5010];
pii edge[5010];
tu f[5010];

void dfs(int u)
{
	for (auto& v : adj[u])
	{
		if (v == p[u]) continue;
		p[v] = u;
		d[v] = d[u] + 1;
		dfs(v);
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
		edge[i] = { u,v };
	}
	d[1] = 1;
	dfs(1);
	memset(ans, -1, sizeof ans);
	cin >> M;
	for (int z = 0; z < M; ++z)
	{
		int u, v, g, mn = INT_MAX;
		cin >> u >> v >> g;
		f[z] = { u,v,g };
		if (d[u] > d[v]) swap(u, v);
		while (d[u] < d[v])
		{
			ans[v] = max(ans[v], g);
			v = p[v];
		}
		while (u != v)
		{
			ans[u] = max(ans[u], g);
			u = p[u];
			ans[v] = max(ans[v], g);
			v = p[v];
		}
	}
	for (int i = 0; i < M; ++i)
	{
		auto& [u, v, g] = f[i];
		int mn = INT_MAX;
		if (d[u] > d[v]) swap(u, v);
		while (d[u] < d[v])
		{
			mn = min(ans[v], mn);
			v = p[v];
		}
		while (u != v)
		{
			mn = min({ ans[u],ans[v],mn });
			u = p[u];
			v = p[v];
		}
		if (mn != g) { cout << -1; return 0; }
	}
	for (int i = 0; i <= N; ++i) if (ans[i] == -1) ans[i] = 1;
	for (int i = 1; i < N; ++i)
	{
		auto& [u, v] = edge[i];
		if (u == p[v]) swap(u, v);
		cout << ans[u] << " ";
	}
}