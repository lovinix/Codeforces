#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
string s;
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (int i = 0; i < s.length();)
	{
		if (s[i] == 'A')
		{
			while (++i < s.length() && s[i] == 'B') ++ans;
		}
		else ++i;
	}
	for (int i = 0; i < s.length();)
	{
		if (s[i] == 'B')
		{
			while (++i < s.length() && s[i] == 'A') ++ans;
		}
		else ++i;
	}
	for (int i = s.length() - 1; i >= 0;)
	{
		if (s[i] == 'A')
		{
			int f = 0;
			while (--i >= 0 && s[i] == 'B') f = 1, ++ans;
			if (f) --ans;
		}
		else --i;
	}
	for (int i = s.length() - 1; i >= 0;)
	{
		if (s[i] == 'B')
		{
			int f = 0;
			while (--i >= 0 && s[i] == 'A') f = 1, ++ans;
			if (f) --ans;
		}
		else --i;
	}
	cout << N * 1LL * (N - 1) / 2 - ans;
}