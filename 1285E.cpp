#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

struct Seg
{
	int l, r, v, cnt, cl, cr, lazy;
	Seg() { l = r = v = cnt = cl = cr = lazy = 0; }
};

int T, N;
pii A[200'010];
vector<Seg> seg(2);

void p(int n, int s, int e);
void u(int l, int r, int v, int n = 1, int s = -1e9, int e = 1e9);
int q(int n = 1, int s = -1e9, int e = 1e9);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		seg.clear();
		for (int i = 0; i < 2; ++i) seg.emplace_back(Seg());
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i].first >> A[i].second;
			u(A[i].first, A[i].second, 1);
		}
		int ans = -1, ansi = -1;
		for (int i = 0; i < N; ++i)
		{
			u(A[i].first, A[i].second, -1);
			if (ans < q()) { ans = q(); ansi = i + 1; }
			u(A[i].first, A[i].second, 1);
		}
		cout << ansi << "\n";
	}
}


void p(int n, int s, int e)
{
	if (!seg[n].lazy) return;
	seg[n].cnt += seg[n].lazy;
	if (seg[n].cnt == 0) seg[n].cl = seg[n].cr = seg[n].v = 0;
	else seg[n].cl = seg[n].cr = seg[n].v = 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg());
	}
	seg[seg[n].l].lazy += seg[n].lazy;
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg());
	}
	seg[seg[n].r].lazy += seg[n].lazy;
	seg[n].lazy = 0;
}

void u(int l, int r, int v, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { seg[n].lazy += v; p(n, s, e); return; }
	int m = s + e >> 1;
	if (!seg[n].l)
	{
		seg[n].l = seg.size();
		seg.emplace_back(Seg());
	}
	u(l, r, v, seg[n].l, s, m);
	if (!seg[n].r)
	{
		seg[n].r = seg.size();
		seg.emplace_back(Seg());
	}
	u(l, r, v, seg[n].r, m + 1, e);
	seg[n].v = seg[seg[n].l].v + seg[seg[n].r].v;
	if (seg[seg[n].l].cr == 1 && seg[seg[n].r].cl == 1) seg[n].v--;
	seg[n].cl = seg[seg[n].l].cl;
	seg[n].cr = seg[seg[n].r].cr;
}

int q(int n, int s, int e)
{
	p(n, s, e);
	return seg[n].v;
}