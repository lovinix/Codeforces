#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		m.clear();
		for (int i = 0; i < N; ++i)
		{
			int v; cin >> v;
			m[v]++;
		}
		int r = 0, ans = 0;
		for (auto& [k, v] : m)
		{
			v += r;
			ans += v / k;
			r = v % k;
		}
		cout << ans << "\n";
	}
}