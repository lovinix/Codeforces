#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, a, b, c;
string s, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> a >> b >> c >> s;
		ans.clear();
		ans.resize(N);
		int cnt = 0;
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == 'R' && b) { ans[i] = 'P'; b--; ++cnt; }
			else if (s[i] == 'P' && c) { ans[i] = 'S'; c--; ++cnt; }
			else if (s[i] == 'S' && a) { ans[i] = 'R'; a--; ++cnt; }
		}
		for (int i = 0; i < s.length(); ++i)
		{
			if (ans[i]) continue;
			if (a) { ans[i] = 'R'; a--; }
			else if (b) { ans[i] = 'P'; b--; }
			else if (c) { ans[i] = 'S'; c--; }
		}
		if (cnt >= N / 2 + N % 2) cout << "YES\n" << ans << "\n";
		else cout << "NO\n";

	}

}