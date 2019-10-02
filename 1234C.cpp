#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		string s[2];
		cin >> s[0] >> s[1];
		int r = 0, c = 0, bef = 0;
		while (!(r == 1 && c == N))
		{
			if (r == 0 && c == N) { cout << "NO\n"; goto next; }
			if (bef == 0 && (s[r][c] == '1' || s[r][c] == '2'))
				c++;
			else if (bef == 1 && (s[r][c] != '1' && s[r][c] != '2'))
				c++, bef = 0;
			else if (bef == 0 && (s[r][c] != '1' && s[r][c] != '2'))
				r ^= 1, bef = 1;
			else
			{
				cout << "NO\n"; goto next;
			}
		}
		cout << "YES\n";
	next:;
	}
}