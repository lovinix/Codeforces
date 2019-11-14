#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, M, mon[200'010], seg[4 * 200'010], seg2[4 * 200'010], tot;
pii her[200'010];

void su(int i, int v, int n = 1, int s = 0, int e = N - 1);
int sq(int l, int r, int n = 1, int s = 0, int e = N - 1);
void su2(int i, int v, int n = 1, int s = 0, int e = M - 1);
int sq2(int l, int r, int n = 1, int s = 0, int e = M - 1);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			su(i, 0);
		for (int i = 0; i < N; ++i)
		{
			cin >> mon[i];
			su(i, mon[i]);
		}
		cin >> M;
		for (int i = 0; i < M; ++i)
			cin >> her[i].first >> her[i].second;
		sort(her, her + M);
		for (int i = 0; i < M; ++i)
			su2(i, 0);
		for (int i = 0; i < M; ++i)
			su2(i, her[i].second);
		tot = 0;
		for (int i = 0; i < N;)
		{
			int l = 1, r = N - i, ans = -1;
			while (l <= r)
			{
				int m = l + r >> 1;
				int mx = sq(i, i + m - 1);
				int idx = lower_bound(her, her + M, pii(mx,0)) - her;
				int mxs = sq2(idx, M - 1);
				if (mxs < m)
				{
					r = m - 1;
					continue;
				}
				else
				{
					l = m + 1;
					ans = m;
				}
			}
			if (ans == -1) { cout << "-1\n"; goto next; }
			else { tot++; i += ans; }
		}
		cout << tot << "\n";
	next:;
	}
}

void su(int i, int v, int n, int s, int e)
{
	
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	if (i <= m) su(i, v, n * 2, s, m);
	else su(i, v, n * 2 + 1, m + 1, e);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

int sq(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return -1;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return max(sq(l, r, n * 2, s, m), sq(l, r, n * 2 + 1, m + 1, e));
}

void su2(int i, int v, int n, int s, int e)
{
	if (s == e) { seg2[n] = v; return; }
	int m = s + e >> 1;
	if (i <= m) su2(i, v, n * 2, s, m);
	else su2(i, v, n * 2 + 1, m + 1, e);
	seg2[n] = max(seg2[n * 2], seg2[n * 2 + 1]);
}

int sq2(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return -1;
	if (l <= s && e <= r) return seg2[n];
	int m = s + e >> 1;
	return max(sq2(l, r, n * 2, s, m), sq2(l, r, n * 2 + 1, m + 1, e));
}