#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, cnt[27];
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> s >> t;
		memset(cnt, 0, sizeof cnt);
		for (auto& c : s)
			cnt[c - 'a']++;
		for (auto& c : t)
		{
			if (cnt[c - 'a'])
			{
				cout << "YES\n";
				goto next;
			}
		}
		cout << "NO\n";
	next:;
	}
}