#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int T, N;
vector<lli> M[200'010];
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			M[i].clear();
		for (int i = 0; i < N; ++i)
		{
			int m; lli p;
			cin >> m >> p;
			M[m].emplace_back(p);
		}
		int prev = N, cnt = 0;
		lli ans = 0;
		for (int i = N - 1; i >= 0; --i)
		{
			prev -= M[i].size();
			for (auto v : M[i]) pq.emplace(-v);
			while (prev + cnt < i) { ans -= pq.top(); pq.pop(); ++cnt; }
		}
		while (pq.size()) pq.pop();
		cout << ans << "\n";
		
	}
}