#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, cnt, lo[100'010], seg[4 * 1'000'010], fl[100'010], hi[100'010];
lli ans;

void u(int i, int v, int n = 1, int s = 0, int e = 1e6)
{
	if (s > i || e < i) return;
	seg[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	u(i, v, n * 2, s, m);
	u(i, v, n * 2 + 1, m + 1, e);
}

int q(int l, int r = 1e6, int n = 1, int s = 0, int e = 1e6)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		lo[i] = INT_MAX;
		int t; cin >> t;
		int f = 0, h = INT_MIN;
		while (t--)
		{
			int v; cin >> v;
			if (v > lo[i]) f = 1;
			lo[i] = min(lo[i], v);
			h = max(h, v);
		}
		if (f) { ++cnt; fl[i] = 1; }
		else 
		{
			hi[i] = h;
			u(h, 1);
		}
	}
	for (int i = 0; i < N; ++i)
	{
		if (fl[i]) { ans += N; }
		else
		{
			ans += cnt + q(lo[i] + 1);
		}
	}
	cout << ans;
}