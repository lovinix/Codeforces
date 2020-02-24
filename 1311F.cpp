#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;
using pil = pair<int, lli>;

struct Seg
{
	int l, r, c; lli v;
	Seg() { l = r = c = v = 0; }
};

int N;
pii A[200'010];
vector<Seg> seg(2);

void u(int i, int n = 1, int s = 1, int e = 1e8)
{
	seg[n].c++;
	seg[n].v += i;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m)
	{
		if (!seg[n].l)
		{
			seg[n].l = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].l, s, m);
	}
	else
	{
		if (!seg[n].r)
		{
			seg[n].r = seg.size();
			seg.emplace_back(Seg());
		}
		u(i, seg[n].r, m + 1, e);
	}
}

pil q(int x, int n = 1, int s = 1, int e = 1e8)
{
	if (s > x) return { 0,0 };
	if (e <= x) return { seg[n].c, seg[n].v };
	int m = s + e >> 1;
	pil lp = q(x, seg[n].l, s, m);
	pil rp = q(x, seg[n].r, m + 1, e);
	return { lp.first + rp.first, 0LL + lp.second + rp.second };
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i].second;
	for (int i = 0; i < N; ++i)
		cin >> A[i].first;
	sort(A, A + N);
	lli ans = 0;
	for (int i = 0; i < N; ++i)
	{
		pil p = q(A[i].second);
		ans += 1LL * p.first * A[i].second - p.second;
		u(A[i].second);
	}
	cout << ans;
}