#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, vst[200'010], par[200'010];
vector<int> adj[200'010];

pii dfs(int u, int p);

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
	pii a = dfs(1, 0);
	pii b = dfs(a.second, 0);
	vst[a.second] = vst[b.second] = 1;
	int v = a.second;
	while (v != 0) { vst[v] = 1; v = par[v]; }
	v = b.second;
	while (v != 0) { vst[v] = 1; v = par[v]; }
	pii c = dfs(b.second, -1);
	cout << b.first + c.first - 1 << "\n";
	if (a.second == c.second || b.second == c.second) { c.second = par[a.second]; }
	cout << a.second << " " << b.second << " " << c.second;
}

pii dfs(int u, int p)
{
	par[u] = p;
	pii ret = { 0,u };
	for (auto& v : adj[u])
	{
		if (v == p) continue;
		ret = max(ret, dfs(v, u));
	}
	ret.first+=!vst[u];
	return ret;
}
