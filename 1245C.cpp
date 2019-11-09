#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli dp[100'010][2], MOD = 1e9 + 7, ans = 1;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	dp[1][1] = 0, dp[1][0] = 1;
	for (int i = 2; i <= 100'000; ++i)
	{
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][0]) % MOD;
		dp[i][1] = dp[i - 1][0];
	}
	cin >> s;
	for (auto& c : s)
	{
		if (c == 'm' || c == 'w') { cout << 0; return 0; }
	}
	for (int i = 0; i < s.length(); ++i)
	{
		int cnt = 0;
		if (s[i] == 'u')
		{
			while (i<s.length() && s[i] == 'u') { ++cnt, ++i; }
			ans = (ans * (dp[cnt][0] + dp[cnt][1])) % MOD;
			--i;
		}
		else if (s[i] == 'n')
		{
			while (i<s.length() && s[i] == 'n') { ++cnt, ++i; }
			ans = (ans * (dp[cnt][0] + dp[cnt][1])) % MOD;
			--i;
		}
	}
	cout << ans;
}