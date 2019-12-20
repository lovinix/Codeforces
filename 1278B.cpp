#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		lli dif = max(a, b) - min(a, b);
		lli sum = 0, i=1;
		while (sum < dif)
		{
			sum += i++;
		}
		while ((sum & 1) ^ (dif & 1))
		{
			sum += i++;
		}
		cout << i - 1 << '\n';

	}
}