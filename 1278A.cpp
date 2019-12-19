#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string p, h;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> p >> h;
		int cnt[26] = { 0, };
		for (auto& c : p)
			cnt[c - 'a']++;
		for (int i = 0; i < h.length(); ++i)
		{
			int tmp[26] = { 0, };
			for (int j = i; j < h.length() && j < i + p.length(); ++j)
			{
				tmp[h[j] - 'a']++;
			}
			for (int j = 0; j < 26; ++j)
			{
				if (tmp[j] != cnt[j]) goto next;
			}
			cout << "YES\n"; goto next2;
			next:;
		}
		cout << "NO\n";
	next2:;
	}
}