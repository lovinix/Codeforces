#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli r, b, k;

lli gcd(lli x, lli y)
{
	if (x < y) swap(x, y);
	return x % y ? gcd(y, x % y) : y;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> r >> b >> k;
		if (r > b) swap(r, b);
		lli g = gcd(r, b);
		lli l = r * b / g;
		if ((b - g) / r + ((b-g)%r?1:0) >= k) { cout << "REBEL\n"; }
		else cout << "OBEY\n";
	}
}