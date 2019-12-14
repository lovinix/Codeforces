#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string s;
vector<int> lst;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		int ans = 0;
		lst.clear();
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 't')
			{
				if ((i + 4) < s.length() && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
				{
					++ans;
					lst.emplace_back(i + 2 + 1);
					i += 4;
					continue;
				}
				if (i + 2 < s.length() && s[i + 1] == 'w' && s[i + 2] == 'o')
				{
					++ans;
					lst.emplace_back(i + 1 + 1);
					i += 2;
					continue;
				}
			}
			if (s[i] == 'o')
			{
				if (i + 2 < s.length() && s[i + 1] == 'n' && s[i + 2] == 'e')
				{
					++ans;
					lst.emplace_back(i + 1 + 1);
					i += 2;
					continue;
				}
			}
		}
		cout << ans << "\n";
		for (auto& i : lst)
			cout << i << " ";
		cout << "\n";
	}
}