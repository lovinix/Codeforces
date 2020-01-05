#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M;
lli fac[250'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	fac[0] = 1;
	for (int i = 1; i <= N; ++i)
		fac[i] = (fac[i - 1] * i) % M;
	lli ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		ans = (ans + ((N - i + 1) * ((fac[i] * fac[N - i + 1]) % M)) % M) % M;
	}
	cout << ans;
}