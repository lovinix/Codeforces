#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, p[200'010], mx[200'010];
lli ans;

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	memset(p, -1, sizeof p);
	for (int i = 1; i <= N; ++i) mx[i] = i;
	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		m(u, v);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (f(i) != i) continue;
		for(int j=i+1;j<=mx[i];++j)
			if (f(j) != i) { ++ans; m(i, j); }
		i = mx[i];
	}
	cout << ans;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	if (u > v) swap(u, v);
	p[v] = u;
	mx[u] = max(mx[u], mx[v]);
}