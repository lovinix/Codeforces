#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, ans;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		while (v % 2 == 0)
			v /= 2;
		m[v]++;
	}
	for (auto& [k,v] : m)
		if (v > 2) ans += v - 2;
	cout << ans;
}