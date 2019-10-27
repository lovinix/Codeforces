#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, cnt[510], ans = -1, ansl, ansr, mn, c;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	int l = 0, r = 0;
	for (auto& c : s)
		c == '(' ? l++ : r++;
	if (l != r) { cout << "0\n1 1"; return 0; }
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			swap(s[i], s[j]);
			l = r = 0;
			mn = INT_MAX;
			for (int k = 0; k < N; ++k)
			{
				s[k] == '(' ? l++ : r++;
				cnt[k] = l - r;
				mn = min(mn, cnt[k]);
			}
			c = 0;
			for (int k = 0; k < N; ++k)
				cnt[k] == mn ? ++c : 0;
			if (ans <= c)
			{
				ans = c;
				ansl = i + 1; ansr = j + 1;
			}
			swap(s[i], s[j]);
		}
	}
	cout << ans << "\n" << ansl << " " << ansr;
}