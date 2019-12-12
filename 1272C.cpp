#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, K;
string s;
set<char> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> s;
	for (int i = 0; i < K; ++i)
	{
		string t; cin >> t;
		st.emplace(t[0]);
	}
	s += '!';
	lli cnt = 0, ans = 0;
	for (int i = 0; i <= N; ++i)
	{
		if (st.count(s[i])) ++cnt;
		else
		{
			ans += cnt * (cnt + 1) / 2;
			cnt = 0;
		}
	}
	cout << ans;
}