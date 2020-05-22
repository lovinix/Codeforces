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
		for (lli i = 3, j = 1; i <= N; i += 2, j++)
		{
			ans += (i * i - (i - 2) * (i - 2)) * j;
		}
		cout << ans << "\n";
	}
}