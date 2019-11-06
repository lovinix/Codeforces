#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int k, n, arr[1010], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> k;
	while (k--)
	{
		cin >> n;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		sort(arr, arr + n);
		reverse(arr, arr + n);
		ans = 0;
		for (int i = 0; i < n && ans <= min(i + 1, arr[i]); ++i)
			ans = min(i + 1, arr[i]);
		cout << ans << "\n";
	}
}