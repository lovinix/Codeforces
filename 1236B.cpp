#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1e9+7;
int N, M;

lli po(lli a, lli b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	cout << po(po(2, M) - 1, N);
}

lli po(lli a, lli b)
{
	lli ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret * a) % MOD;
		a = (a * a) % MOD;
		b >>= 1;
	}
	return ret;
}