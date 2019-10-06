#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int bias = 200'000;
int N, M, arr[200'020], seg[4 * 400'020];
lli ans;
vector<int> idx;

void u(int i, int n = 1, int s = 0, int e = 400'000);
int q(int l, int r, int n = 1, int s = 0, int e = 400'000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (arr[i] == M) idx.emplace_back(i);
	}
	for (int i = idx.size() - 1; i >= 0; --i)
	{
		int lo = 0, hi = 0, k = idx.size() - i - 1;
		int j;
		for (j = idx[i] + 1; j < N && arr[j] != M; ++j)
		{
			if (arr[j] > M) hi++;
			else if (arr[j] < M) lo++;
			u(hi - lo + bias);
			if (hi == lo || hi - lo == 1) ++ans;
		}
		if (j != N && arr[j] == M) u(hi - lo + bias);
		lo = hi = 0;
		for (j = idx[i]; j >= 0 && (i == 0 ? 1 : j != idx[i - 1]); --j)
		{
			if (arr[j] > M) hi++;
			else if (arr[j] < M) lo++;
			if (hi - lo >= -k || hi - lo < k) ++ans;
			ans += q(lo - hi - k + bias, lo - hi + k + bias);
		}
	}
	cout << ans;
}

void u(int i, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n]++;
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) u(i, n * 2, s, m);
	else u(i, n * 2 + 1, m + 1, e);
}

int q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return q(l, r, n * 2, s, m) + q(l, r, n * 2 + 1, m + 1, e);
}