#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int Q, N, dp[300'010];
vector<int> vt(300'010);
pii idx[300'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		for (int i = 0; i <= N; ++i)
			idx[i] = { INT_MIN,INT_MAX };
		for (int i = 0; i < N; ++i)
		{
			int v; cin >> v;
			vt[i] = v;
			idx[v] = { max(idx[v].first,i),min(idx[v].second,i) };
		}
		sort(vt.begin(), vt.begin() + N);
		int sz = unique(vt.begin(), vt.begin() + N) - vt.begin();
		dp[0] = 1;
		for (int i = 0; i < sz; ++i)
		{
			if (idx[vt[i]].first < idx[vt[i + 1]].second)
				dp[i + 1] = dp[i] + 1;
			else
				dp[i + 1] = 1;
		}
		int ans = 0;
		for (int i = 0; i < sz; ++i) ans = max(ans, dp[i]);
		cout << sz - ans << "\n";
	}
}