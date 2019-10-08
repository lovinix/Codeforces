#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, b, p, f, h, c, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> b >> p >> f >> h >> c;
		ans = 0;
		if (h < c) { swap(h, c); swap(p, f); }
		int t = min(b / 2, p);
		ans += t * h;
		b -= t*2;
		if (b) ans += min(b / 2, f) * c;
		cout << ans << "\n";
	}
}