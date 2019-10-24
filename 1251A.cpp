#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, cnt[26];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		s += ' ';
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < s.length() - 1; ++i)
		{
			char c = s[i];
			int cur = 1;
			while (s[i] == s[i + 1]) ++i, ++cur;
			cnt[c - 'a'] |= cur & 1;
		}
		for (int i = 0; i < 26; ++i)
			if (cnt[i] & 1) cout << (char)(i + 'a');
		cout << "\n";
	}
}