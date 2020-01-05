#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, K;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> K >> s;
		int f = 1, cnt = 0;
		while (f)
		{
			f = 0;
			for (int i = 0; i < s.length() - 1; ++i)
			{
				if (s[i] == 'A' && s[i+1]!='A') { s[++i] = 'A'; f = 1; }
			}
			if (f) ++cnt;
		}
		cout << cnt << '\n';
	}
}