#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, C, A[200'010], B[200'010], dp[200'010][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> C;
	for (int i = 1; i < N; ++i)
		cin >> A[i];
	for (int i = 1; i < N; ++i)
		cin >> B[i];
	dp[1][1] = C;
	for (int i = 2; i <= N; ++i)
	{
		dp[i][0] = min(dp[i - 1][0] + A[i - 1], dp[i - 1][1] + A[i - 1]);
		dp[i][1] = min(dp[i - 1][0] + B[i - 1] + C, dp[i - 1][1] + B[i - 1]);
	}
	for (int i = 1; i <= N; ++i)
	{
		cout << min(dp[i][0], dp[i][1]) << " ";
	}
}