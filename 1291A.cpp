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
		while (s.size() && (s.back() - '0') % 2 == 0) s.pop_back();
		if (s.empty()) { cout << "-1\n"; continue; }
		int sum = 0, idx = s.length() - 1;
		for (; idx >= 0; --idx)
		{
			sum += s[idx] - '0';
			if (sum % 2 == 0)
			{
				for (int j = idx; j < s.length(); ++j)
					cout << s[j];
				cout << '\n';
				goto next;
			}
		}
		cout << "-1\n";
	next:;
	}
}