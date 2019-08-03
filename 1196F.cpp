#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, lli>;

auto cmp = [](tu& t1, tu& t2) {return get<2>(t1) > get<2>(t2); };

int n, m, k;
vector<tu> dist;
priority_queue < tu, vector<tu>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		pq.emplace(u, v, w);
	}
	int cnt = 0;
	while (1)
	{
		int u, v; lli w;
		tie(u, v, w) = pq.top();
		pq.pop();
		for (auto& t : dist)
		{
			int a, b; lli c;
			tie(a, b, c) = t;
			if ((a == u && b == v && c <= w) || (a == v && b == u && c <= w)) goto end;
		}
		for (auto& t : dist)
		{
			int a, b; lli c;
			tie(a, b, c) = t;
			if (a == u || b == u)
			{
				if (a == u) pq.emplace(v, b, c + w);
				else if (b == u) pq.emplace(a, v, c + w);
			}
			if (a == v || b == v)
			{
				if (a == v) pq.emplace(u, b, c + w);
				else if (b == v) pq.emplace(a, u, c + w);
			}
		}
		cnt++;
		if(cnt==k)
		{
			cout << w;
			return 0;
		}
		dist.emplace_back(u, v, w);
	end:;
	}
}