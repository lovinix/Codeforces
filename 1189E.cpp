#include<bits/stdc++.h>
#define lli long long int
using namespace std;

map<int, int> m;
lli ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, p, k;
	cin >> n >> p >> k;
	for (int i = 0; i < n; ++i)
	{
		lli a;
		cin >> a;
		int b = (((a * a) % p) * ((a * a) % p) + p - ((k * a) % p)) % p;
		m[b]++;
	}
	for (auto v : m)
	{
		lli b = v.second;
		ans += (b * (b - 1)) / 2;
	}
	cout << ans;
}