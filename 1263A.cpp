#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, arr[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> arr[0] >> arr[1] >> arr[2];
		int ans = 0;
		sort(arr, arr + 3);
		int dif = min(arr[0], arr[2] - arr[1]);
		ans += dif;
		arr[0] -= dif; arr[2] -= dif;
		ans += (arr[0] / 2) * 2;
		arr[1] -= arr[0] / 2;
		arr[2] -= arr[0] / 2;
		ans += min(arr[1], arr[2]);
		cout << ans << "\n";

	}
}