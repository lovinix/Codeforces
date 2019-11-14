#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int t, n, x, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> n >> x >> a >> b;
		if (a > b) swap(a, b);
		while (x && a > 1) { a--; x--; }
		while (x && b < n) { b++; x--; }
		cout << b - a << "\n";
	}
}