#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N;
vector<pii> tmp;
map<int, int> m;
deque<pii> dq;
vector<int> ans[400'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t;
		cin >> t;
		m[t]++;
	}
	int sqrtN = sqrt(N);
	for (auto& [i, v] : m)
		tmp.emplace_back(i, v);
	sort(tmp.begin(), tmp.end(), [](pii& p1, pii& p2) {return p1.second > p2.second; });
	N -= sqrtN * sqrtN;
	int c = min((int)tmp.size(), sqrtN);
	int idx = 0;
	for (idx = 0; idx<c; ++idx)
	{
		dq.emplace_back(tmp[idx].first, min(sqrtN,tmp[idx].second));
	}
	int r = sqrtN + N / sqrtN;
	int i = 0, j = 0;
	for (; i < r; ++i)
	{
		for (j = 0; j < c; ++j)
		{
			auto [v, n] = dq.front();
			dq.pop_front();
			if (i != 0 && ans[i - 1][j] == v) goto end;
			ans[i].emplace_back(v);
			if (!--n)
			{
				if (i == r - 1) continue;
				if (idx < tmp.size()) { dq.emplace_back(tmp[idx].first, tmp[idx].second); ++idx; }
				else { if (j == c - 1) ++i; goto end; }
			}
			else dq.emplace_back(v, n);
		}
		if (dq.size())
		{
			auto [v, n] = dq.front();
			dq.pop_front();
			dq.emplace_back(v, n);
		}
	}
end:
	cout << i * ans[0].size() << "\n" << i << " " << ans[0].size() << "\n";
	for (int k = 0; k < i; ++k)
	{
		for (auto& v : ans[k])
			cout << v << " ";
		cout << "\n";
	}
}