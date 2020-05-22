#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

auto cmp = [](pii& p1, pii& p2) { return  p1.second - p1.first == p2.second - p2.first ? p1.first > p2.first : p1.second - p1.first < p2.second - p2.first; };
int T, N, ans[200'010];
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		while (!pq.empty()) pq.pop();
		cin >> N;
		pq.emplace(1, N);
		int c = 1;
		while (!pq.empty())
		{
			auto [l, r] = pq.top();
			pq.pop();
			if (l > r) continue;
			if ((r - l + 1) % 2)
			{
				ans[(l + r) / 2] = c++;
				if (l == r) continue;
				pq.emplace(l, (l + r) / 2 - 1);
				pq.emplace((l + r) / 2 + 1, r);
			}
			else
			{
				ans[(l + r - 1) / 2] = c++;
				pq.emplace(l, (l + r - 1) / 2 - 1);
				pq.emplace((l + r - 1) / 2 + 1, r);
			}
		}
		for (int i = 1; i <= N; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}