#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
set<int> s;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		s.clear(); m.clear();
		for (int i = 0; i < N; ++i)
		{
			int v; cin >> v;
			s.emplace(v);
			m[v]++;
		}
		int ans = -1;
		for (auto& [k, v] : m)
		{
			ans = max({ ans, min(int(s.size() - s.count(k)),v), min(int(s.size()),int(v - s.count(k))) });
		}
		cout << ans << "\n";
	}
}