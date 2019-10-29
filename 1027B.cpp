#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N, Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	while (Q--)
	{
		lli x, y;
		cin >> x >> y;
		if (N & 1)
		{
			if (x & 1)
				cout << (((x - 1) / 2) * (N / 2) + ((x - 1) / 2) * (N / 2 + 1) + (y + 1) / 2 + ((y & 1) ? 0 : N * N / 2 + 1)) << "\n";
			else
				cout << ((x / 2)*(N / 2 + 1) + ((x - 1) / 2) * (N / 2) + ((y & 1) ? N * N / 2 + (y + 1) / 2 : y / 2)) << "\n";
		}
		else
			cout << (x - 1) * N / 2 + (y - 1) / 2 + 1 + ((y & 1) == (x & 1) ? 0 : (N * N) / 2) << "\n";
	}
}