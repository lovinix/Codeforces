#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	int cur = 0, ans = 0;
	for (int i = 0; i < s.length(); ++i)
	{
		int c = s[i] - '0';
		if (c % 3 == 0) { ++ans; s[i] = '9'; continue; }
		for (int j = i - 1; j>=0 && s[j] != '9'; --j)
		{
			c += s[j] - '0';
			if (c % 3 == 0) { s[i] = '9'; ++ans; break; }
		}
	}
	cout << ans;
}