#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli Q, a, b, n, S;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> a >> b >> n >> S;
		if (min(S / n, a) * n + b >= S) cout << "YES\n";
		else cout << "NO\n";
	}
}