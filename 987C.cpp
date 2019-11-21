#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Seg
{
	int l, r, v;
	Seg() : l(0), r(0), v(INT_MAX) {}
};

int N, s[3010], c[3010];
vector<Seg> seg(2);

void u(int i, int v, int n=1, int s=1, int e=1e9)
{
	seg[n].v = min(seg[n].v, v);
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m)
	{
		if (seg[n].l == 0)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].l, s, m);
	}
	else
	{
		if (seg[n].r == 0)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, v, seg[n].r, m + 1, e);
	}
}

int q(int l, int r = 1e9, int n = 1, int s = 1, int e = 1e9)
{
	if (s > r || e < l) return INT_MAX;
	if (l <= s && e <= r) return seg[n].v;
	int m = s + e >> 1;
	int ret = INT_MAX;
	if (seg[n].l) ret = min(ret, q(l, r, seg[n].l, s, m));
	if (seg[n].r) ret = min(ret, q(l, r, seg[n].r, m + 1, e));
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> s[i];
	for (int i = 0; i < N; ++i)
		cin >> c[i];
	int ans = INT_MAX;
	for (int j = N - 1; j >= 0; --j)
	{
		for (int i = j - 1; i >= 0; --i)
		{
			if (s[i] < s[j])
			{
				int k = q(s[j] + 1);
				if (k != INT_MAX) ans = min(ans, c[i] + c[j] + k);
			}
		}
		u(s[j], c[j]);
	}
	if (ans == INT_MAX) cout << -1;
	else cout << ans;
}