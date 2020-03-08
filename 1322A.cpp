#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	int lp = 0, rp = 0;
	for (auto& c : s)
		(c == '(' ? lp : rp)++;
	if (lp != rp) { cout << -1; return 0; }
	int ans = 0;
	for (int l = 0, r = 0, mn = 0, cnt = 0; r <= s.length();)
	{
		if (r == s.length())
		{
			if (mn < 0) ans += r - l;
			break;
		}
		cnt += (s[r++] == '(' ? 1 : -1);
		mn = min(mn, cnt);
		if (cnt == 0)
		{
			if (mn < 0) ans += r - l;
			l = r;
			mn = 0;
		}
	}
	cout << ans;
}