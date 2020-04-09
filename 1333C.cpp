#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
map<lli, lli> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	m[0] = 1;
	lli ps = 0, ans = 0;
	for (int i = 2; i <= N + 1; ++i)
	{
		int v; cin >> v;
		ps += v;
		if (m[ps])
		{
			ans += ;
		}
		m[ps] = i;
	}
	cout << (1LL * N * (N + 1) / 2 - ans);
}