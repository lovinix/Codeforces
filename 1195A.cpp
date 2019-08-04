#include <bits/stdc++.h>
using namespace std;

int n,k, cnt[1001], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		++cnt[t];
	}
	for (int i = 1; i <= k; ++i)
	{
		ans += cnt[i] / 2 + cnt[i] % 2;
	}
	cout << ans;
}