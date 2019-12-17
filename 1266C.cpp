#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli r, c;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> r >> c;
	if (r == 1 && c == 1) { cout << 0; return 0; }
	if (r == 1 && c != 1 || r != 1 && c == 1)
	{
		int st = 2;
		for (int i = 0; i < r; ++i)
		{
			for (int j = 0; j < c; ++j)
				cout << st++ << " ";
			cout << '\n';
		}
		return 0;
	}
	int st = 2;
	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			if (j == 0) cout << st << " ";
			else
			{
				cout << st * (r + j + 1) << " ";
			}
		}
		st++;
		cout << "\n";
	}

}