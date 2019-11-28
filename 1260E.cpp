#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, arr[2'000'010], idx;
lli ans;
priority_queue<pii,vector<pii>, greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		if (arr[i] == -1) idx = i;
	}
	while (N>idx)
	{
		for (int j = N/2 + 1; j <= N; ++j)
		{
			pq.emplace(arr[j], j);
		}
		auto [v, id] = pq.top();
		pq.pop();
		ans += v;
		N >>= 1;
	}
	cout << ans;
}