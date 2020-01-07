#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, seg[4 * 2010], P[2010], C[2010], W[2010], ans[2010], root;
vector<int> adj[2010];

int dfs(int u);
void dfs2(int u);
void su(int i, int v, int n = 1, int s = 1, int e = 2000);
int sq(int k, int n = 1, int s = 1, int e = 2000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int p, c;
		cin >> p >> c;
		C[i] = c;
		P[i] = p;
		adj[P[i]].emplace_back(i);
		if (p == 0) root = i;
	}
	for (int i = 1; i <= 2000; ++i)
		su(i, 1);
	dfs(root);
	dfs2(root);
	cout << "YES\n";
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}

int dfs(int u)
{
	W[u] = 1;
	for (auto& v : adj[u])
		if (v == P[u]) continue;
		else W[u] += dfs(v);
	return W[u];
}

void dfs2(int u)
{
	if (C[u] >= W[u]) { cout << "NO"; exit(0); }
	ans[u] = sq(C[u] + 1);
	su(ans[u], -1);
	for (auto& v : adj[u])
		if (v == P[u]) continue;
		else dfs2(v);
}

void su(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	su(i, v, n * 2, s, m);
	su(i, v, n * 2 + 1, m + 1, e);
}

int sq(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (seg[n * 2] >= k) return sq(k, n * 2, s, m);
	else return sq(k - seg[n * 2], n * 2 + 1, m + 1, e);
}