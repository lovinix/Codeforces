#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N;
lli s, x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		s = x = 0;
		for (int i = 0; i < N; ++i)
		{
			int t; cin >> t;
			s += t;
			x ^= t;
		}
		cout << 2 << '\n';
		cout << x << " " << x + s << "\n";
	}
}