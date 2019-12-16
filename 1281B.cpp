#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s >> t;
		if (s < t) { cout << s << "\n"; goto next; }
		for (int i = 0; i < s.length(); ++i)
		{
			char c = s[i]; int idx = -1;
			for (int j = i + 1; j < s.length(); ++j)
			{
				if (c >= s[j]) { idx = j; c = s[j]; }
			}
			if (idx == -1) continue;
			swap(s[i], s[idx]);
			if (s < t) { cout << s << '\n'; goto next; }
			swap(s[i], s[idx]);
		}
		cout << "---\n";
	next:;
	}
}