#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, tot;
vector<lli> p, co;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		if (v == 1) { co.emplace_back(i); ++tot; }
	}
	if (tot == 1) { cout << -1; return 0; }
	for (int i = 2; i <= tot; ++i)
	{
		if (tot % i == 0) { p.emplace_back(i); }
	}
	lli ans = LLONG_MAX;
	for (auto& k : p)
	{
		lli cost = 0;
		for (int i = 0; i < co.size(); i += k)
		{
			for (int j = 0; j < k; ++j)
			{
				cost += abs(co[i + k / 2] - co[i + j]);
			}
		}
		ans = min(ans, cost);
	}
	cout << ans;
}