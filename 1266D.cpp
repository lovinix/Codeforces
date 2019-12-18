#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pil = pair<int, lli>;
using tu = tuple<int, int, lli>;

int N, M;
lli arr[100'010];
vector<pil> m, p;
vector<tu> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arr[u] -= w;
		arr[v] += w;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (arr[i] < 0) m.emplace_back(i, -arr[i]);
		if (arr[i] > 0) p.emplace_back(i, arr[i]);
	}
	while (!m.empty())
	{
		auto [i, d] = m.back();
		m.pop_back();
		while (d)
		{
			auto& [j, e] = p.back();
			lli mn = min(d, e);
			ans.emplace_back(i, j, mn);
			d -= mn;
			e -= mn;
			if (e == 0) p.pop_back();
		}
	}
	cout << ans.size() << "\n";
	for (auto& [i, j, d] : ans)
		cout << i << " " << j << " " << d << "\n";
}