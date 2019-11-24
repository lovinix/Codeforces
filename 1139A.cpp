#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli ans;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (int i = 0; i < N; ++i)
	{
		if ((s[i] - '0') % 2 == 0)
			ans += i + 1;
	}
	cout << ans;
}