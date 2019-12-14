#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		lli ans = 0;
		for (int i = 1; i <= 9; ++i)
		{
			lli tmp = i;
			lli cnt = 0;
			while (tmp <= N)
			{
				cnt++;
				tmp = tmp * 10 + i;
			}
			ans += cnt;
		}
		cout << ans << "\n";
	}
}