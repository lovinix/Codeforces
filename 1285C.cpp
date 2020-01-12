#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli X;

lli gcd(lli a, lli b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> X;
	for (lli t = sqrt(X); t >= 1; --t)
	{
		if (X % t) continue;
		if (gcd(t, X / t) == 1) { cout << t << " " << X / t; return 0; }
	}
}