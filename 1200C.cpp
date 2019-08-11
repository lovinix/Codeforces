#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli n, m, q;

lli gcd(lli a, lli b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m >> q;
	lli g = gcd(n, m);
	lli b = m / g;
	lli a = n / g;
	while(q--)
	{
		lli sx, sy, ex, ey;
		lli f, s;
		cin >> sx >> sy >> ex >> ey;
		if (sx == 1) f = (sy - 1) / a;
		else f = (sy - 1) / b;
		if (ex == 1) s = (ey - 1) / a;
		else s = (ey - 1) / b;
		if (f == s) cout << "YES\n";
		else cout << "NO\n";
	}
}

lli gcd(lli a, lli b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}
