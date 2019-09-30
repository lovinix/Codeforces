#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;

const int MOD = 1e9 + 7;
lli x, n;
lli ans = 1;

lli po(lli a, lli b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> n;
	for (int i = 2; i*i <= x; ++i)
	{
		if ((x % i) == 0)
		{
			lli tmp = i, bef = 0;
			lli cnt = 0;
			while (n / tmp)
			{
				cnt += n / tmp;
				bef = tmp;
				tmp *= i;
				if (bef >= tmp) break;
			}
			ans = (ans * po(i, cnt)) % MOD;
		}
		while ((x % i) == 0) x /= i;
	}
	lli tmp = x, bef = 0, cnt = 0;
	while (x!=1 && n / x)
	{
		cnt += n / tmp;
		bef = tmp;
		tmp *= x;
		if (bef >= tmp) break;
	}
	ans = (ans * po(x, cnt)) % MOD;
	cout << ans;
}

lli po(lli a, lli b)
{
	if (!b) return 1;
	if (b == 1) return a;
	if (b & 1) return (a * po((a * a) % MOD, b / 2)) % MOD;
	else return po((a * a) % MOD, b / 2) % MOD;
}