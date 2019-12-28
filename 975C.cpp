#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, Q;
lli pa[200'010], b[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; ++i)
	{
		lli t; cin >> t;
		pa[i] = pa[i - 1] + t;
	}
	for (int i = 1; i <= Q; ++i)
	{
		cin >> b[i];
	}
	lli s = 0;
	for (int i = 1; i <= Q; ++i)
	{
		s += b[i];
		int idx = lower_bound(pa, pa + N + 1, s) - pa;
		if (idx == N + 1) { cout << N << "\n"; s = 0; }
		else 
		{
			if (s == pa[idx])
			{
				cout << (N - idx == 0 ? N : N - idx) << "\n";
				if (N - idx == 0) s = 0;
			}
			else
				cout << N - idx + 1 << "\n";
		}
	}
}