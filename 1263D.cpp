#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, p[26], cnt[26], arr[200'010][26];

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

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	memset(p, -1, sizeof p);
	for (int i = 0; i < N; ++i)
	{
		string s;
		cin >> s;
		for (auto& c : s)
		{
			arr[i][c - 'a']++;
			cnt[c - 'a']++;
		}
		for (int j = 0; j < 26; ++j)
		{
			for (int k = j + 1; k < 26; ++k)
			{
				if (arr[i][j] > 0 && arr[i][k] > 0)
					m(j, k);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < 26; ++i)
	{
		if (cnt[i] > 0 && p[i] < 0) ++ans;
	}
	cout << ans;
}