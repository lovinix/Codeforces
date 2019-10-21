#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, mx, l, r;
string s;

int tst();

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (int i = 0; i < N; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			int cur = 0;
			swap(s[i], s[j]);
			cur = tst();
			swap(s[i], s[j]);
			if (cur >= mx) { mx = cur; l = i + 1, r = j + 1; }
		}
	}
	cout << mx << "\n" << l << " " << r;
}

int tst()
{
	stack<char> stk;
	int i = 0;
	int ret = 0;
	int cnt[2] = { 0, };
	for (; i < N; ++i)
	{
		if (s[i] == '(') ++cnt[0];
		else ++cnt[1];
		if (cnt[0] == cnt[1]) ++ret;
	}
	return ret;
}