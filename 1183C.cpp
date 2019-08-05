#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli q, k, n, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> k >> n >> a >> b;
		int l = 0, r = n;
		int ans = -1;
		while (l <= r)
		{
			int m = (l + r) / 2;
			if (m * a + (n - m) * b < k)
			{
				ans = m;
				l = m + 1;
			}
			else
			{
				r = m - 1;
			}
		}
		cout << ans << "\n";	
	}
}