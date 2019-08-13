#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n;
lli ans=1;
lli g,arr[400'001];

lli gcd(lli a, lli b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	g = arr[0];
	for (int i = 0; i < n; ++i)
		g = gcd(g, arr[i]);
	for(int i=2;g>1&&i<=1'000'000;++i)
	{
		int cnt = 0;
		while (g%i == 0) cnt++, g /= i;
		if (cnt) ans *= cnt + 1;
	}
	if (g>1) ans *= 2;
	cout << ans;
	
}

lli gcd(lli a, lli b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}