#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli T, N, A, B, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> A >> B >> s;
		s += '0';
		int h = 1;
		lli ans = -A;
		for (int i = 0; i < s.length(); ++i)
		{
			if (h == 1 && s[i] == '0') { ans += A + B; continue; }
			if (h == 1 && s[i] == '1') { ans += 2 * A + 2 * B; h = 2; continue; }
			if (h == 2 && s[i] == '1') { ans += A + 2 * B; continue; }
			if (h == 2 && s[i] == '0')
			{
				ans += A + 2 * B;
				lli cnt = 0;
				while (i<s.length() && s[i] == '0') { ++i; ++cnt; }
				if (cnt == 1) { ans += A + 2 * B; continue; }
				if (i == s.length())
				{
					ans += (cnt-1) * B + cnt * A;
					break;
				}
				lli hi = (A+2*B)*cnt;
				lli lo = (cnt - 1) * B + 2 * B + cnt * A + 2 * A;
				ans += min(hi, lo);
			}
		}
		cout << ans << "\n";
	}
}