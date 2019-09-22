#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, cnt;
string s, t, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (int i = 0; i < N; i += 2)
	{
		t = s.substr(i, 2);
		if (t == "ab" || t == "ba") ans += t;
		else { ans += "ab"; ++cnt; }
	}
	cout << cnt << "\n" << ans;
}