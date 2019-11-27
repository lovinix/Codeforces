#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (2 * a < b) { cout << "NO\n"; continue; }
		if ((a + b) % 3) { cout << "NO\n"; }
		else cout << "YES\n";
	}
}