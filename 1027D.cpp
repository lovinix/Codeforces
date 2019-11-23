#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, cost[200'010], n[200'010], f[200'010], cnt, scc[200'010], sccnum, vst[200'010], ans;
vector<int> adj[200'010], stk, lst[200'010];

int dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> cost[i];
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		adj[i].emplace_back(v);
	}
	for (int i = 1; i <= N; ++i)
		if (!n[i]) dfs(i);
	for (int i = 1; i <= N; ++i)
	{
		for (auto& v : adj[i])
		{
			if (vst[scc[i]]) continue;
			if (scc[v] != scc[i]) continue;
			vst[scc[i]] = 1;
			int tmp = INT_MAX;
			for (auto& k : lst[scc[i]])
				tmp = min(tmp, cost[k]);
			ans += tmp;
		}
	}
	cout << ans;
}

int dfs(int u)
{
	n[u] = ++cnt;
	int ret = n[u];
	stk.emplace_back(u);
	for (auto& v : adj[u])
	{
		if (!n[v]) ret = min(ret, dfs(v));
		else if (!f[v]) ret = min(ret, n[v]);
	}
	if (ret == n[u])
	{
		while (1)
		{
			int c = stk[stk.size() - 1];
			stk.pop_back();
			f[c] = 1;
			scc[c] = sccnum;
			lst[sccnum].emplace_back(c);
			if (c == u) { ++sccnum; break; }
		}
	}
	return ret;
}