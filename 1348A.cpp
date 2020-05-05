#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli T, N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		lli ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			ans += (i >= N / 2 && i <= N - 1) ? -(1 << i) : 1 << i;
		}
		cout << ans << '\n';
	}
}