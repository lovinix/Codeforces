#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int N;
lli lazy[4 * 1'000'010];
pll seg[4 * 1'000'010];
char s[1'000'010];
string t;

void p(int n, int s, int e)
{
	if (!lazy[n]) return;
	seg[n].first += lazy[n];
	seg[n].second += lazy[n];
	if (s == e) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void u(int l, int r, int v, int n = 1, int s = 0, int e = t.size())
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += v; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, v, n * 2, s, m);
	u(l, r, v, n * 2 + 1, m + 1, e);
	seg[n].first = max(seg[n * 2].first, seg[n * 2 + 1].first);
	seg[n].second = min(seg[n * 2].second, seg[n * 2 + 1].second);
}

pll q(int l, int r, int n = 1, int s = 0, int e = t.size())
{
	p(n, s, e);
	if (s > r || e < l) return { LLONG_MIN, LLONG_MAX };
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	pll r1 = q(l, r, n * 2, s, m);
	pll r2 = q(l, r, n * 2 + 1, m + 1, e);
	return { max(r1.first,r2.first),min(r1.second,r2.second) };
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	cin.get();
	cin.getline(s, N + 1);
	for (int i = 0; i <= N; ++i)
		t += ' ';
	int cur = 0;
	for (int i = 0; i < N; ++i)
	{
		char& c = s[i];
		switch (c)
		{
		case 'L':
			if (cur) cur--;
			break;
		case 'R':
			++cur;
			break;
		default:
			int dif = t[cur] == '(' ? -1 : t[cur] == ')' ? 1 : 0;
			dif += c == '(' ? 1 : c == ')' ? -1 : 0;
			t[cur] = c;
			u(cur, t.size(), dif);
			break;
		}
		pll ret = q(0, t.size());
		if (ret.second < 0 || q(t.size(), t.size()).second != 0) { cout << "-1 "; }
		else cout << ret.first << " ";
	}
	
}