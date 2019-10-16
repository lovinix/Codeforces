#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[2][100'010], dp[2][100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < 2; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];
	dp[0][1] = arr[0][1];
	dp[1][1] = arr[1][1];
	for (int i = 2; i <= N; ++i)
	{
		dp[0][i] = max({ dp[1][i - 1], dp[0][i - 2], dp[1][i - 2] }) + arr[0][i];
		dp[1][i] = max({ dp[0][i - 1], dp[1][i - 2], dp[0][i - 2] }) + arr[1][i];
	}
	cout << max({ dp[0][N],dp[1][N],dp[0][N - 1],dp[1][N - 1] });
}