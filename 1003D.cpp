#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, Q, cnt[33];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		for(int i=31;i>=0;--i)
			if (v & 1 << i) { cnt[i]++; break; }
	}
	while (Q--)
	{
		int q; cin >> q;
		int ans = 0;
		int tmp[33];
		for (int i = 0; i < 33; ++i) tmp[i] = cnt[i];
		for (int i = 0; i < 32; ++i)
		{
			if (q & 1 << i)
			{
				int cur = 1;
				for (int j = i; j >= 0; --j)
				{
					if (tmp[j] >= cur) { tmp[j] -= cur; ans += cur; cur = 0; break; }
					else
					{
						cur -= tmp[j]; ans += tmp[j]; tmp[j] = 0;
						cur *= 2;
					}
				}
				if (cur) { cout << "-1\n"; goto next; }
			}
		}
		cout << ans << "\n";

	next:;
	}
}