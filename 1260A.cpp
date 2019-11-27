#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N, C, S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> C >> S;
		lli m = S / C, r = S % C;
		lli ans = 0;
		for (int i = 0; i < C; ++i)
		{
			ans += (m + (r ? 1 : 0)) * (m + (r ? 1 : 0));
			if (r) r--;
		}
		cout << ans << '\n';
	}
}