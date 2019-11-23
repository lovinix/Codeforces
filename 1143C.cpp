#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, p[100'010], res[100'010], root, pnt[100'010];
vector<int> c[100'010], ans;

int f(int u)
{
	return pnt[u] < 0 ? u : pnt[u] = f(pnt[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	pnt[v] += pnt[u];
	pnt[u] = v;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(pnt, -1, sizeof pnt);
	for (int i = 1; i <= N; ++i)
	{
		int j, k;
		cin >> j >> k;
		res[i] = k;
		p[i] = j;
		if (j == -1) root = i;
		else c[j].emplace_back(i);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (res[i] == 0) continue;
		for (auto& j : c[i])
			if (res[j] == 0) goto next;
		m(i, 0);
	next:;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (f(i) == f(0)) ans.emplace_back(i);
	}
	if (ans.empty()) { cout << -1; return 0; }
	for (auto& i : ans)
		cout << i << " ";
}