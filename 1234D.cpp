#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e5 + 10;
int Q, seg[4 * MAX][27], N, query[26];
string s;

void u(int i, int f, int t, int n = 1, int s = 0, int e = N - 1);
void q(int l, int r, int n = 1, int s = 0, int e = N - 1);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> Q;
	N = s.length();
	for (int i = 0; i < N; ++i)
	{
		u(i, 26, s[i] - 'a');
	}
	while (Q--)
	{
		int f, pos, l, r; char c;
		cin >> f;
		if (f == 1)
		{
			cin >> pos >> c;
			--pos;
			u(pos, s[pos] - 'a', c - 'a');
			s[pos] = c;
		}
		else
		{
			cin >> l >> r;
			l--, r--;
			for (int i = 0; i < 26; ++i) query[i] = 0;
			q(l, r);
			int cnt = 0;
			for (int i = 0; i < 26; ++i)
				if (query[i]) cnt++;
			cout << cnt << "\n";
		}
	}
}

void u(int i, int f, int t, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n][f]--;
	seg[n][t]++;
	if (s == e) return;
	int m = s + e >> 1;
	u(i, f, t, n * 2, s, m);
	u(i, f, t, n * 2 + 1, m + 1, e);
}

void q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return;
	if (l <= s && e <= r)
	{
		for (int i = 0; i < 26; ++i) 
			query[i] += seg[n][i];
		return;
	}
	int m = s + e >> 1;
	q(l, r, n * 2, s, m);
	q(l, r, n * 2 + 1, m + 1, e);
}