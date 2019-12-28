#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

lli N, A, B;
pll arr[200'010];
map<lli, lli> m;
map<pll, lli> mxy;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A >> B;
	for (int i = 0; i < N; ++i)
	{
		lli x, vx, vy;
		cin >> x >> vx >> vy;
		arr[i] = { vx,vy };
		m[A * vx - vy]++;
		mxy[{vx, vy}]++;
	}
	lli ans = 0;
	for (int i = 0; i < N; ++i)
	{
		auto& [vx, vy] = arr[i];
		lli t = A * vx - vy;
		if (m[t]) ans += m[t] - mxy[{vx, vy}];
	}
	cout << ans;
}