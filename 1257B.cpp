#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> x >> y;
		while (x < y)
		{
			if (x & 1) 
				if (x == 1) { cout << "NO\n"; goto next; }
				else x--;

			else 
			{
				if (x == 2 && y!=3) 
				{
					cout << "NO\n"; goto next;
				}
				else 
					x = 3 * x / 2;
			}
		}
		cout << "YES\n";
		next:;
	}
}