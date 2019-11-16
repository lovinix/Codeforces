#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[200'010], ans = LLONG_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < 2 * N; ++i)
		cin >> arr[i];
	sort(arr, arr + 2 * N);
	for (int i = 1; i + N - 1 < 2 * N; ++i)
	{
		ans = min(ans, (arr[2 * N - 1] - arr[0]) * (arr[i + N - 1] - arr[i]));
	}
	ans = min(ans,(arr[N - 1] - arr[0]) * (arr[2 * N - 1] - arr[N]));
	cout << ans;
}