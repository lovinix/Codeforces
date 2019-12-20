#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, A[100'010], ans, tmp[100'010];
pii B[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		ans = INT_MAX;
		for (int i = 1; i <= N; ++i)
		{
			int t; cin >> t;
			A[i] = A[i - 1] + (t == 1 ? 1 : -1);
		}
		for (int i = 0; i < N; ++i)
			cin >> tmp[i];
		B[N] = { 0,N };
		for (int i = N-1; i >= 0; --i)
		{
			B[i] = { B[i + 1].first + (tmp[i] == 1 ? 1 : -1),i };
		}
		sort(B, B + N + 1);
		for (int i = 0; i <= N; ++i)
		{
			int idx = lower_bound(B, B + N + 1, pii(-A[i], 0)) - B;
			if (idx == N + 1) continue;
			if (B[idx].first != -A[i]) continue;
			ans = min(ans, N - i + B[idx].second);
		}
		cout << ans << '\n';
	}
}