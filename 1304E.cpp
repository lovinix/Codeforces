#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

constexpr int sz = 100'010;
int N, Q, w[sz], d[sz], p[sz], hld[sz], num[sz], node_num;
vector<int> adj[sz];

void dfs(int u)
{
	w[u] = 1;
	for (auto& v : adj[u])
	{
		if (w[v] == 0)
		{
			p[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
			w[u] += w[v];
		}
	}
}

void dfs2(int u)
{
	int cc = -1;
	num[u] = ++node_num;
	for (auto& v : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[v] > w[cc]))
			cc = v;
	}
	if (cc != -1) { hld[cc] = hld[u]; dfs2(cc); }
	for (auto& v : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v);
		}
	}
}

int dist(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret += num[u] - num[hld[u]] + 1;
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return ret + num[v] - num[u];
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
	}
	dfs(1);
	dfs2(1);
	cin >> Q;
	while (Q--)
	{
		int x, y, a, b, k;
		cin >> x >> y >> a >> b >> k;
		int ab = dist(a, b), ax = dist(a, x), ay = dist(a, y), xy = 1, xb = dist(x, b), yb = dist(y, b);
		if ((ab <= k && ab % 2 == k % 2) || (ax + xy + yb <= k && (ax + xy + yb) % 2 == k % 2) || (ay + xy + xb <= k && (ay + xy + xb) % 2 == k % 2))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}