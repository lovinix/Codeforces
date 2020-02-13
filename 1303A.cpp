#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		int f = 0, cnt = 0, ans = 0;
		for (auto& c : s)
		{
			if (f == 0 && c == '1')
			{
				f = 1;
			}
			else if (f == 1 && c == '0')
			{
				cnt++;
			}
			else if (f == 1 && c == '1')
			{
				ans += cnt;
				cnt = 0;
			}
		}
		cout << ans << "\n";
	}
}