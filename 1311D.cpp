#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, A, B, C, ansa, ansb, ansc;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A >> B >> C;
		int ans = INT_MAX;
		for (int i = 1; i <= C; ++i)
		{
			int dif = abs(i - A);
			for (int j = i; j <= C + i; j += i)
			{
				int dif2 = dif + abs(j - B);
				int tmp[3];
				tmp[0] = (C / j) * j;
				tmp[1] = tmp[0] - j;
				tmp[2] = tmp[0] + j;
				for (int k = 0; k < 3; ++k)
				{
					if (tmp[k] < j || tmp[k] <= 0) continue;
					if (int curans = dif2 + abs(tmp[k] - C); curans < ans)
					{
						ansa = i;
						ansb = j;
						ansc = tmp[k];
						ans = curans;
					}
				}
			}
		}
		cout << ans << "\n";
		cout << ansa << " " << ansb << " " << ansc << "\n";
	}
}