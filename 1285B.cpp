#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, A[100'010];
lli dp[100'010][2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		lli s = 0;
		for (int i = 1; i <= N; ++i)
		{
			cin >> A[i];
			s += A[i];
			if (i == N) dp[i][0] = LLONG_MIN;
			else dp[i][0] = dp[i - 1][0] >= 0 ? dp[i - 1][0] + A[i] : A[i];
			if (i == 1) dp[i][1] = LLONG_MIN;
			else dp[i][1] = dp[i - 1][1] >= 0 ? dp[i - 1][1] + A[i] : A[i];
		}
		lli mx = LLONG_MIN;
		for (int i = 1; i <= N; ++i)
			mx = max({ mx, dp[i][0],dp[i][1] });
		if (mx < s) cout << "YES\n";
		else cout << "NO\n";
	}
}