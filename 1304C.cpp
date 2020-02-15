#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int Q, N, M;
tu A[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N >> M;
		A[0] = { 0,M,M };
		for (int i = 1; i <= N; ++i)
		{
			int t, l, h;
			cin >> t >> l >> h;
			A[i] = { t,l,h };
		}
		for (int i = 1; i <= N; ++i)
		{
			auto& [t1, l1, h1] = A[i - 1];
			auto& [t2, l2, h2] = A[i];
			int l3 = max(l2, l1 - (t2 - t1));
			int h3 = min(h2, h1 + (t2 - t1));
			if (l3 > h2 || h3 < l2) { goto next; }
			l2 = max(l2, l3);
			h2 = min(h2, h3);
		}
		cout << "YES\n";
		continue;
	next:
		cout << "NO\n";
	}
}