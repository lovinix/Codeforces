#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

const int MAX = 1e9;
int T, N, arr[200'010];
vector<pii> cnt[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cnt[i].clear();
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
			if (cnt[arr[i]].size())
				cnt[arr[i]].back().second = i;
			cnt[arr[i]].emplace_back(i, MAX);
		}
		if (N == 1) { cout << "-1\n"; continue; }
		int ans = INT_MAX;
		for (int i = 1; i <= N; ++i)
		{
			for (auto& [l, r] : cnt[i])
				ans = min(ans, r - l + 1);
		}
		cout << (ans > N ? -1 : ans) << "\n";
	}
}