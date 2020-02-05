#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N;
lli sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		sum = 0;
		int o = 0, e = 0;
		while (N--)
		{
			int t; cin >> t;
			sum += t;
			o |= t & 1;
			e |= !(t & 1);
		}
		if ((sum & 1) or (o and e)) cout << "YES\n";
		else cout << "NO\n";
	}
}