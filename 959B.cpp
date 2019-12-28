#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, K, M;
lli p[100'010];
string str[100'010];
map<string, int> mp;

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	p[u] = max(p[u], p[v]);
	p[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(p, -1, sizeof p);
	cin >> N >> K >> M;
	for (int i = 1; i <= N; ++i)
		cin >> str[i];
	for (int i = 1; i <= N; ++i)
	{
		int c;
		cin >> c;
		mp[str[i]] = i;
		p[i] = -c;
	}
	for (int i = 0; i < K; ++i)
	{
		int x;
		cin >> x;
		int tmp;
		for (int j = 0; j < x; ++j)
		{
			if (j == 0) cin >> tmp;
			else
			{
				int v; cin >> v;
				m(tmp, v);
			}
		}
	}
	lli ans = 0;
	for (int i = 0; i < M; ++i)
	{
		string s;
		cin >> s;
		ans += -p[f(mp[s])];
	}
	cout << ans;
}