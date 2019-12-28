#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using lli = long long;

lli MOD = 998244353;
int N, cnt[1'000'010];
vector<int> adj[1'000'010];

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
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; ++j)
		{
			int a; cin >> a;
			adj[i].emplace_back(a);
			cnt[a]++;
		}
	}
	lli ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		for (auto& a : adj[i])
		{
			ans += (((inv_mod(N) * inv_mod(adj[i].size())) % MOD) * ((cnt[a] * inv_mod(N)) % MOD)) % MOD;
			ans %= MOD;
		}
	}
	cout << ans;
}