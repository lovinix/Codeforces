#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, p, w, d;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> p >> w >> d;
	for (int y = 0; y < w; ++y)
	{
		lli tmp = p - y * d;
		if (tmp % w == 0)
		{
			lli x = tmp / w;
			if (x + y > n || x < 0) { cout << -1; return 0; }
			cout << x << " " << y << " " << n - x - y;
			return 0;
		}
	}
	cout << -1;
}