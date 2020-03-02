#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	s = ' ' + s + ' ';
	t = s;
	int ans = 0, cnt = 0;
	for (char c = 'b'; c <= 'z'; ++c)
	{
		for (int i = 1; i < s.length() - 1; ++i)
		{
			if (s[i] == c && (s[i - 1] == c - 1 || s[i + 1] == c - 1))
			{
				s.erase(i, 1);
				i = 0;
				++cnt;
			}
		}
	}
	ans = max(ans, cnt);
	cnt = 0;
	for (char c = 'z'; c > 'a'; --c)
	{
		for (int i = 1; i < t.length() - 1; ++i)
		{
			if (t[i] == c && (t[i - 1] == c - 1 || t[i + 1] == c - 1))
			{
				t.erase(i, 1);
				i = 0;
				++cnt;
			}
		}
	}
	ans = max(ans, cnt);
	cout << ans;
}