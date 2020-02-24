#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, D, cnt[5010], fl[5010];
queue<int> q[5010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		memset(fl, 0, sizeof fl);
		cin >> N >> D;
		for (int i = 1; i <= N; ++i) { while (!q[i].empty()) q[i].pop(); }
		int mx = 0;
		for (int i = 1; i < N; ++i) mx += i;
		int mn = 0, t = 4;
		for (int i = 2, d = 1; i <= N; ++i)
		{
			if (i == t) { ++d; t *= 2; }
			mn += d;
		}
		if (D<mn || D>mx) { cout << "NO\n"; continue; }
		cout << "YES\n";
		iota(cnt + 2, cnt + N + 1, 1);
		int dif = mx - D, curd = 1, dt = 1, pos = 1, idx = N;
		while (dif)
		{
			int m = min(cnt[idx] - curd, dif);
			cnt[idx] -= m;
			dif -= m;
			dt--;
			--idx;
			if (dt == 0) { curd++; dt = (1 << curd) - 1; }
		}
		for (int i = 2; i <= N; ++i)
			q[cnt[i]].emplace(i);
		q[0].emplace(1);
		for (int i = 2; i <= N; ++i)
		{
			int v = q[cnt[i] - 1].front();
			cout << v << " ";
			if (fl[v]) q[cnt[i] - 1].pop();
			else fl[v]++;
		}
		cout << '\n';
	}
}