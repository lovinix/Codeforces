#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, arr[300'010], visit[300'010], ans;
pii total;
vector<int> adj[300'010];

pii dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		if (arr[i] == 1) total.first++;
		if (arr[i] == 2) total.second++;
	}
	for (int i = 1; i < N; ++i)
	{
		int u, v; cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	dfs(1);
	cout << ans;
}

pii dfs(int u)
{
	visit[u] = 1;
	pii cur = { 0,0 };
	if (arr[u] == 1) cur.first++;
	if (arr[u] == 2) cur.second++;
	for (auto& v : adj[u])
	{
		if (visit[v]) continue;
		pii ret = dfs(v);
		if (ret.first == 0 && ret.second == total.second) ++ans;
		if (ret.second == 0 && ret.first == total.first) ++ans;
		cur.first += ret.first;
		cur.second += ret.second;
	}
	return cur;
}