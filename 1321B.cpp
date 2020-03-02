#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
map<int, lli> m;

int main()
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int v; cin >> v;
		m[v - i] += v;
	}
	lli ans = 0;
	for (auto& [k, v] : m)
	{
		ans = max(ans, v);
	}
	cout << ans;
}