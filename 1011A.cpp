#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> s;
	sort(s.begin(), s.end());
	if (K == 1) { cout << s[0] - 'a' + 1; return 0; }
	for (int i = 0; i < s.length(); ++i)
	{
		int cnt = 1, ans = s[i] - 'a' + 1;
		char cur = s[i];
		for (int j = i + 1; j < s.length(); ++j)
		{
			if (s[j] - cur <= 1) continue;
			ans += s[j] - 'a' + 1;
			++cnt;
			cur = s[j];
			if (cnt == K) { cout << ans; return 0; }
		}
	}
	cout << -1;
}