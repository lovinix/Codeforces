#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> s;
		for (int i = 0, j = N - 1; i <= j; ++i, --j)
		{
			if (s[i] == s[j] || s[i] + 1 == s[j] - 1 || s[i] - 1 == s[j] + 1)
				continue;
			else
			{
				cout << "NO\n"; goto next;
			}
		}
		cout << "YES\n";
	next:;
	}
}