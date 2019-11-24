#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, K, p[100'010];
lli ans, MOD = 1e9 + 7;

int f(int u);
void m(int u, int v);
lli power(lli x, lli y);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	memset(p, -1, sizeof p);
	for (int i = 1; i < N; ++i)
	{
		int u, v, x;
		cin >> u >> v >> x;
		if (x == 1) continue;
		m(u, v);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (p[i] < 0) ans = (ans + power(-p[i], K)) % MOD;
	}
	cout << (power(N, K) - ans + MOD) % MOD;
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	p[u] += p[v];
	p[v] = u;
}

lli power(lli x, lli y)
{
	if (y == 0) return 1;
	lli ret = (power(x, y >> 1)* power(x, y >> 1)) % MOD;
	return y & 1 ? (x * ret) % MOD : ret;
}