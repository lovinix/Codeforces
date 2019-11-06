#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int k, n;
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	while (k--)
	{
		cin >> n >> s >> t;
		for (int i = 0; i < n; ++i)
		{
			if (s[i] != t[i])
			{
				for (int j = i + 1; j < n; ++j)
				{
					if (s[j]!=t[j] && t[i] == t[j]) { swap(s[i], t[j]); goto next; }
				}
			}
		}
	next:
		if (s == t) { cout << "Yes\n"; }
		else { cout << "No\n"; }
	}
}