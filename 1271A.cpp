#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int a, b, c, d, e, f, ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a >> b >> c >> d >> e >> f;
	if (e > f)
	{
		int mn = min(a, d);
		ans += e * mn;
		d -= mn;
		ans += min({ b,c,d }) * f;
	}
	else
	{
		int mn = min({ b,c,d });
		ans += f * mn;
		d -= mn;
		ans += min(a, d) * e;
	}
	cout << ans;
}