#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, arr[200'010];
map<int, int> l,r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	int idx = -1;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (arr[i] == M) idx = i;
	}
	lli ans = 1;
	int lo = 0, hi = 0;
	for (int i = idx + 1; i < N; ++i)
	{
		if (arr[i] > M) { hi++; }
		else if (arr[i] < M) { lo++; }
		if (r.count(hi - lo)) r[hi - lo]++;
		else r[hi - lo] = 1;
		if (hi - lo == 1 || hi == lo) ++ans;
	}
	hi = lo = 0;
	for (int i = idx - 1; i >= 0; --i)
	{
		if (arr[i] > M) hi++;
		else if (arr[i] < M) lo++;
		if (r.count(lo - hi)) ans += r[lo - hi];
		if (r.count(lo - hi + 1)) ans += r[lo - hi + 1];
		if (hi - lo == 1 || hi == lo) ++ans;
	}
	cout << ans;
}