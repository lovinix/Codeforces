#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = unsigned long long;
using pll = pair<lli, lli>;

lli x0, yk, ax, ay, bx, by, xs, ys, t, ans;

vector<pll> vt;

lli dist(lli x1, lli x2, lli y1, lli y2)
{
	return max(x1, x2) - min(x1, x2) + max(y1, y2) - min(y1, y2);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x0 >> yk >> ax >> ay >> bx >> by >> xs >> ys >> t;
	vt.emplace_back(x0, yk);
	while (vt.back().first <= 1e17 && vt.back().second <= 1e17)
		vt.emplace_back(vt.back().first * ax + bx, vt.back().second * ay + by);
	for (int i = 0; i < vt.size(); ++i)
	{
		lli d = dist(xs, vt[i].first, ys, vt[i].second);
		if (d > t) continue;
		lli sum = d, cnt = 1;
		for (lli j = i + 1; j < vt.size(); ++j)
		{
			lli curd = dist(vt[j - 1].first, vt[j].first, vt[j - 1].second, vt[j].second);
			if (sum + curd > t) break;
			sum += curd;
			++cnt;
		}
		ans = max(ans, cnt);
		sum = d, cnt = 1;
		for (int j = i - 1; j >= 0; --j)
		{
			lli curd = dist(vt[j + 1].first, vt[j].first, vt[j + 1].second, vt[j].second);
			if (sum + curd > t) break;
			sum += curd;
			++cnt;
		}
		ans = max(ans, cnt);
	}
	cout << ans;
}