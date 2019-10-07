#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int Q, N;
lli arr[200'010];
int x, a, y, b;
lli k;

int gcd(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		cin >> x >> a >> y >> b >> k;
		if (x < y) 
		{
			swap(x, y); swap(a, b);
		}
		sort(arr, arr + N, [](lli& a, lli& b) {return a > b; });
		int l = 1, r = N;
		lli lcm = (lli)a*(lli)b/gcd(a, b);
		int ans = -1;
		while (l <= r)
		{
			int m = l + r >> 1;
			lli sum = 0;
			int i = 0;
			for (; i < m / a; ++i) sum += x * arr[i] / 100;
			for (; i < m / a + m / b - m/lcm; ++i) sum += y * arr[i] / 100;
			for (i = 0; i < m / lcm; ++i) sum += y * arr[i] / 100;
			if (sum >= k)
			{
				ans = m;
				r = m - 1;
			}
			else
				l = m + 1;
		}
		cout << ans << "\n";
	}
}

int gcd(int u, int v)
{
	if (u < v) swap(u, v);
	return u % v ? gcd(v, u % v) : v;
}