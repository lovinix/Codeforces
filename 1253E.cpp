#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long;

int N, M;
lli dp[100][100'010], ans;
pii arr[100];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	memset(dp, 0x3f, sizeof dp);
	for (int i = 1; i <= N; ++i)
	{
		int x, s;
		cin >> x >> s;
		arr[i] = { max(0,x - s),min(M,x + s) };
	}
	sort(arr, arr + N + 1);
	for (int i = 0; i <= M; ++i)
		dp[0][i] = i;
	for (int i = 1; i <= N; ++i)
	{
		auto& [l, r] = arr[i];
		for (int j = 0; j < l; ++j)
			dp[i][j] = dp[i - 1][j];
		for (int j = l; j <= r; ++j)
			dp[i][j] = dp[i - 1][max(0,l - 1)];
		for (int j = 1; j + r <= M; ++j)
			dp[i][r + j] = min(dp[i - 1][r + j], dp[i][max(0,l - j - 1)] + j);
	}
	cout << dp[N][M];
}