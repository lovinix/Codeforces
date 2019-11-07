#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	lli cnt = 0, mn = INT_MAX, tmp = N;
	for (lli i = 2; i * i <= N; ++i)
	{
		if (N % i == 0)
		{
			++cnt; mn = min(mn, i);
			while (N % i == 0) N /= i;
		}
	}
	if (N != tmp && N > 1) ++cnt;
	if (cnt == 0) cout << N;
	else if (cnt == 1) cout << mn;
	else cout << 1;
}