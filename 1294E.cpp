#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, cnt[200'010], ans;
vector<int> A[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int u; cin >> u;
			A[i].emplace_back(u);
		}
	}
	for (int j = 0; j < M; ++j)
	{
		for (int i = 0; i < N; ++i) { cnt[i] = 0; }
		for (int i = 0; i < N; ++i)
		{
			if (A[i][j] > N* M) continue;
			if (A[i][j] % M != (j + 1)%M) continue;
			int pos = A[i][j] / M;
			if (j == M - 1) { pos = (pos + N - 1)%N; }
			cnt[pos<=i?i-pos:i+N-pos]++;
		}
		int cur = INT_MAX;
		for (int i = 0; i < N; ++i)
		{
			cur = min(cur, i + (N - cnt[i]));
		}
		ans += cur;
	}
	cout << ans;
}