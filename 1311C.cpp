#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M, P[200'010], cnt[200'010][26], ans[26];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> s;
		for (int i = 0; i < M; ++i)
			cin >> P[i];
		P[M] = s.length();
		for (int i = 1; i <= s.length(); ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				cnt[i][j] = cnt[i - 1][j] + (s[i - 1] - 'a' == j ? 1 : 0);
			}
		}
		memset(ans, 0, sizeof ans);
		for (int i = 0; i <= M; ++i)
		{
			for (int j = 0; j < 26; ++j)
			{
				ans[j] += cnt[P[i]][j];
			}
		}
		for (int i = 0; i < 26; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}