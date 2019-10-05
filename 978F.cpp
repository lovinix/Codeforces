#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, arr[200'010], sorted[200'010];
vector<int> adj[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		sorted[i - 1] = arr[i];
	}
	sort(sorted, sorted + N);
	for (int i = 0; i < K; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].emplace_back(v);
		adj[v].emplace_back(u);
	}
	for (int i = 1; i <= N; ++i)
	{
		int cnt = lower_bound(sorted, sorted + N, arr[i]) - sorted;
		for (auto& v : adj[i])
			if (arr[v] < arr[i]) --cnt;
		cout << cnt << " ";
	}
}