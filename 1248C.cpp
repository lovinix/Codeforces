#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1e9 + 7;
int N, M;
lli dp[100'010][2];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	dp[1][0] = dp[1][1] = 1;
	dp[2][0] = dp[2][1] = 2;
	for (int i = 3; i <= max(N, M); ++i)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 2][1]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 2][0]) % MOD;
	}
	cout << (dp[N][0] + dp[N][1] + dp[M][0] + dp[M][1] - 2) % MOD;
}

