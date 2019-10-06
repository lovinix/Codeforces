#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s >> t;
	int cnt = 0;
	for (int i = s.length() - 1, j = t.length() - 1; i >= 0 && j >= 0; --i, --j)
	{
		if (s[i] == t[j]) cnt += 2;
		else break;
	}
	cout << s.length() + t.length() - cnt;
}
