#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, a, b, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		int t = min(b, c / 2);
		b -= t;
		t += min(a, b / 2);
		cout << 3 * t << "\n";
	}
}