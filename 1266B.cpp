#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> x;
		if (x < 14 || x % 14 == 0 || x % 14 > 6) { cout << "NO\n"; }
		else cout << "YES\n";
	}
}