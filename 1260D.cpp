#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli M, N, K, T, arr[200'010], ans, seg[4*200'010], lazy[4*200'010], mp[200'010];

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n] = max(seg[n], lazy[n]);
	if (s == e) return;
	lazy[n * 2] = max(lazy[n * 2], lazy[n]);
	lazy[n * 2 + 1] = max(lazy[n * 2 + 1], lazy[n]);
	lazy[n] = 0;
}

void u(int l, int r, lli v, int n=1, int s=0, int e=N)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] = max(lazy[n], v); p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int q(int l, int r, int n=1, int s=0, int e=N)
{
	p(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return max(q(l, r, n * 2, s, m), q(l, r, n * 2 + 1, m + 1, e));
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> M >> N >> K >> T;
	for (int i = 0; i < M; ++i)
		cin >> arr[i];
	sort(arr, arr + M);
	for (int i = 0; i < K; ++i)
	{
		lli l, r, d;
		cin >> l >> r >> d;
		u(l, r, d);
	}
	for (int i = 0; i <= N; ++i)
		mp[i] = q(i, i);
	lli l = 0, r = 200'000;
	while (l <= r)
	{
		lli m = l + r >> 1;
		lli cnt = arr + M - lower_bound(arr, arr + M, m);
		lli t = N + 1;
		for (int i = 0; i <=N; ++i)
		{
			if (mp[i] <= m) continue;
			int tmp = 0;
			while (mp[i] > m) { i++; tmp++; }
			i--;
			t += 2*tmp;
		}
		if (t <= T) { ans = max(ans, cnt); r = m - 1; }
		else l = m + 1;
	}
	cout << ans;
}