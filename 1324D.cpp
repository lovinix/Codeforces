#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

struct Seg
{
	int l, r, v;
	Seg() { l = r = v = 0; }
};

int N, A[200'010], B[200'010];
vector<Seg> seg(2);

void su(int i, int n = 1, int s = -1e9, int e = 1e9)
{
	if (s > i || e < i) return;
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
		su(i, seg[n].l, s, m);
	}
	else
	{
		if (seg[n].r == 0)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		su(i, seg[n].r, m + 1, e);
	}
}

int sq(int i, int n = 1, int s = -1e9, int e = 1e9)
{
	if (s > i) return seg[n].v;
	if (e <= i) return 0;
	int m = s + e >> 1;
	return sq(i, seg[n].l, s, m) + sq(i, seg[n].r, m + 1, e);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
		cin >> B[i];
	long long ans = 0;
	for (int i = 0; i < N; ++i)
	{
		ans += sq(-A[i] + B[i]);
		su(A[i] - B[i]);
	}
	cout << ans;
}