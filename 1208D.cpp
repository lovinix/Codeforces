#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, res[200'001];
lli arr[200'001], tree[4 * 200'001];

void u(int i, int v, int n = 1, int s = 1, int e = N);
lli q(int r, int n = 1, int s = 1, int e = N);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 1; i <= N; ++i)
		u(i, i);
	for (int i = N - 1; i >= 0; --i)
	{
		int l = 1, r = N, ans=N+1;
		while (l <= r)
		{
			int m = l + r >> 1;
			if (q(m) > arr[i]) { ans = m; r = m - 1; }
			else { l = m + 1; }
		}
		u(ans, -ans);
		res[i] = ans;
	}
	for (int i = 0; i < N; ++i)
		cout << res[i] << " ";

}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	tree[n] += v;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) u(i, v, n * 2, s, m);
	else u(i, v, n * 2 + 1, m + 1, e);
}

lli q(int r, int n, int s, int e)
{
	if (s > r) return 0;
	if (e <= r) return tree[n];
	int m = s + e >> 1;
	if (r <= m) return q(r, n * 2, s, m);
	else return tree[n * 2] + q(r, n * 2 + 1, m + 1, e);
}