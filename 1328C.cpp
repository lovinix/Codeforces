#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
string x;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> x;
		int f = 0;
		string a="1", b="1";
		for (int i = 1; i < x.length(); ++i)
		{
			char& c = x[i];
			if (c == '2') { a += f ? '0' : '1'; b += f ? '2' : '1'; }
			else if (c == '1') { a += f ? '0' : '1'; b += f ? '1' : '0'; f = 1; }
			else { a += '0'; b += '0'; }
		}
		cout << a << '\n' << b << '\n';
	}
}