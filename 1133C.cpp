#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Seg
{
	int l, r, v;
	Seg() : l(0), r(0), v(0) {}
};

int N, arr[200'010];
vector<Seg> seg(2);

void u(int i, int n = 1, int s = 1, int e = 1e9)
{
	seg[n].v++;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m)
	{
		if (seg[n].l == 0)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].l, s, m);
	}
	else
	{
		if (seg[n].r == 0)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].r, m + 1, e);
	}
}

int q(int l, int r, int n = 1, int s = 1, int e = 1e9)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n].v;
	int m = s + e >> 1;
	int ret = 0;
	if (seg[n].l) ret+=q(l, r, seg[n].l, s, m);
	if (seg[n].r) ret += q(l, r, seg[n].r, m + 1, e);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		u(arr[i]);
	}
	int ans = -1;
	for (int i = 0; i < N; ++i)
	{
		ans = max(ans, q(arr[i], arr[i] + 5));
	}
	cout << ans;
}