#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

string s;
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	lli cur = 1;
	for (auto& c : s)
		cur *= c - '0';
	ans = max(cur, ans);
	for (int i = 0; i < s.length(); ++i)
	{
		cur = 1;
		if (s[i] == '0') break;
		if (s[i] == '1')
		{
			for (int j = i + 1; j < s.length(); ++j)
				cur *= 9;
			ans = max(ans, cur);
			break;
		}
		for (int j = 0; j < i; ++j)
			cur *= s[j] - '0';
		cur *= s[i] - '0' - 1;
		for (int j = i + 1; j < s.length(); ++j)
			cur *= 9;
		ans = max(ans, cur);
	}
	cout << ans;
}