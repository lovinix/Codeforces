#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, ans[200'010];
pii arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i].first;
			arr[i].second = i;
		}
		sort(arr, arr + N);
		int mn = INT_MAX, mx = INT_MIN;
		for (int i = 0; i < N; ++i)
		{
			auto& [n, idx] = arr[i];
			mn = min(mn, idx);
			mx = max(mx, idx);
			ans[n] = mx - mn + 1 == n ? 1 : 0;
		}
		for (int i = 1; i <= N; ++i)
			cout << ans[i];
		cout << "\n";
	}
}