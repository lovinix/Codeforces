#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli N, D;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> D;
		int x = 0;
		for (; x + D / (x + 1) + (D % (x + 1) ? 1 : 0) >= (x + 1) + D / (x + 2) + (D % (x + 2) ? 1 : 0); x++);
		if (x + D / (x + 1) + (D % (x + 1) ? 1 : 0) > N) cout << "NO\n";
		else cout << "YES\n";
	}
}