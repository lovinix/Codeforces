#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
const char str[] = "abc";
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		string tmp;
		cin >> tmp;
		s = "a";
		s += tmp;
		s += "a";
		for (int i = 1; i < s.length() - 2; ++i)
			if (s[i] != '?' && s[i] == s[i + 1])
			{
				cout << "-1\n";
				goto next;
			}
		for (int i = 1; i < s.length() - 1; ++i)
		{
			if (s[i] != '?') continue;
			int j = i + 1;
			while (j < s.length() && s[j] == s[i]) j++;
			int l = i, r = j - 1;
			for (char st = (s[l-1] == s[r+1] ? str[(s[l-1] - 'a' + 1)%3] : ('a' ^ 'b' ^ 'c' ^ s[l-1] ^ s[r+1])); l <= r; l++, r--)
			{
				s[l] = s[r] = st;
				st = str[(st - 'a' + 1) % 3];
			}
			if (l-r==1) s[l] = 'a' ^ 'b' ^ 'c' ^ s[r] ^ s[l+1];
			i = j - 1;
		}
		for (int i = 1; i < s.length() - 1; ++i)
			cout << s[i];
		cout << "\n";
	next:;
	}
}