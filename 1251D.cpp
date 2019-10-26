#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int T, N;
lli S, l, r;
pll arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> S;
		l = INT_MAX, r = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i].first >> arr[i].second;
			l = min(l, arr[i].first);
			r = max(r, arr[i].second);
		}
		sort(arr, arr + N);
		lli ans = -1;
		while (l <= r)
		{
			lli sum = 0, m = l + r >> 1;
			int cnt = 0;
			for (int i = N - 1; i >= 0; --i)
			{
				if (arr[i].first > m) { ++cnt; sum += arr[i].first; continue; }
				if (arr[i].second < m) { sum += arr[i].first; continue; }
				if (cnt < N / 2 + 1) { sum += m; ++cnt; }
				else sum += arr[i].first;
			}
			if (cnt >= N / 2 + 1 && sum <= S) { ans = m; l = m + 1; }
			else r = m - 1;
		}
		cout << ans << "\n";
	}
}