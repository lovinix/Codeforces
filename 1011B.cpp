#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, cnt[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int m; cin >> m;
		cnt[m]++;
	}
	int l = 1, r = M, ans = 0;
	while (l <= r)
	{
		int m = l + r >> 1;
		int c = 0;
		for (int i = 1; i <= 100; ++i)
		{
			c += cnt[i] / m;
		}
		if (c >= N) { ans = m; l = m + 1; }
		else r = m - 1;
	}
	cout << ans;
}