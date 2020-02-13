#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli N, G, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> G >> B;
		lli l = N, r = 2 * 1e18, ans, s = G + B;
		while (l <= r)
		{
			lli m = l + r >> 1;
			lli cur = (m / s) * G;
			cur += min(m % s, G);
			if (cur >= N / 2 + (N & 1)) { r = m - 1; ans = m; }
			else l = m + 1;
		}
		cout << ans << "\n";
	}
}