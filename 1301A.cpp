#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string a, b, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c;
		for (int i = 0; i < a.length(); ++i)
		{
			if (c[i] == a[i] || c[i] == b[i]) continue;
			cout << "NO\n";
			goto next;
		}
		cout << "YES\n";
	next:;
	}
}