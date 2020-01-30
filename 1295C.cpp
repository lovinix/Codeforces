#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, dp[100'010][26], pos[26];
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s >> t;
		memset(pos, -1, sizeof pos);
		memset(dp, -1, sizeof dp);
		for (int i = 0; i < s.length(); ++i)
		{
			if (pos[s[i] - 'a'] == -1) pos[s[i] - 'a'] = i;
			for (int j = i - 1; j >= 0; --j)
			{
				dp[j][s[i] - 'a'] = i;
				if (s[i] == s[j]) break;
			}
		}
		int ans = 0;
		for (int i = 0; i < t.length(); ++ans)
		{
			if (pos[t[i] - 'a'] == -1) { cout << "-1\n"; goto next; }
			int cnt = 0, idx = pos[t[i]-'a'];
			while (idx>=0 && i + ++cnt < t.length())
			{
				idx = dp[idx][t[i + cnt] - 'a'];
			}
			i += cnt;
		}
		cout << ans << '\n';
	next:;
	}
}