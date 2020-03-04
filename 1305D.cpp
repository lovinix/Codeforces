#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
set<int> adj[1010], s;

int main()
{
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace(v);
		adj[v].emplace(u);
	}
	if (N == 2) { cout << "? 1 2" << endl; int t; cin >> t; cout << "! " << t << endl; return 0; }
	for (int i = 1; i <= N; ++i)
		if (adj[i].size() == 1) s.emplace(i);
	int ans = 0;
	for (int i = 1; i <= N; ++i) ans ^= i;
	while (s.size() > 1)
	{
		int u, v;
		u = *(s.begin()); s.erase(u);
		v = *(s.begin()); s.erase(v);
		cout << "? " << u << " " << v << endl;
		int lca;
		cin >> lca;
		if (lca == u || lca == v) { cout << "! " << lca << endl; return 0; }
		adj[*adj[u].begin()].erase(u);
		adj[*adj[v].begin()].erase(v);
		adj[u].clear();
		adj[v].clear();
		ans ^= u;
		ans ^= v;
		for (int i = 1; i <= N; ++i)
		{
			if (adj[i].size() == 1) s.emplace(i);
		}
	}
	cout << "! "<< ans << endl;
}