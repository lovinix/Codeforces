#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

constexpr lli MOD = 998244353;
lli N, M;

lli power_mod(int a, int b, int N) {
	if (b == 0) return 1;
	else if (b == 1) return a % MOD;
	else if (b % 2) return power_mod(a, b - 1, N) * (long long)a % N;

	int p = power_mod(a, b / 2, N);
	return p * (long long)p % N;
}

lli inv_mod(int a, int p = MOD) {
	return power_mod(a, p - 2, p);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	lli ans = 1, comb = 1;
	for (lli i = N - 1; i < M; ++i)
	{
		comb = (((comb * i) % MOD) * inv_mod(i - (N - 2))) % MOD;
		ans = (ans + comb) % MOD;
	}
	cout << ans;
}