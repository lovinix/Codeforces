#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		cin >> s;
		int z = 0, t = 0, sum = 0;
		for (auto& c : s)
		{
			int v = c - '0';
			if (v == 0) z++;
			if (v % 2 == 0) t++;
			sum += v;
		}
		if (z == 0) cout << "cyan\n";
		else
		{
			z--; t--;
			if (sum % 3 == 0 && t)
				cout << "red\n";
			else
				cout << "cyan\n";
		}
	}
}