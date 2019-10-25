#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string str;

auto cmp = [](char c1, char c2) {c1 -= '0'; c2 -= '0'; return (c1 & 1) == (c2 & 1) ? 0 : (c1 & 1 ? 0 : 1); };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> str;
		stable_sort(str.begin(), str.end(), cmp);
		int l = -1, r = INT_MAX;
		for(int i=0;i<str.length();++i)
			if ((str[i] - '0') % 2 == 0) { l = i; break; }
		for(int i=0;i<str.length();++i)
			if ((str[i] - '0') & 1) { r = i; break; }
		if (l == -1 || r == INT_MAX)
		{
			cout << str << "\n";
			continue;
		}
		int i = l, j = r;
		string ans;
		while (i < r && j < str.length())
		{
			if (str[i] < str[j]) ans += str[i++];
			else ans += str[j++];
		}
		while (i < r) ans += str[i++];
		while (j < str.length()) ans += str[j++];
		cout << ans << "\n";
	}
}