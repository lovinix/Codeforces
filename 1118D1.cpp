#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, arr[200'010];
lli sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i]; 
		sum += arr[i];
	}
	if (sum < M) { cout << -1; return 0; }
	sort(arr, arr + N);
	reverse(arr, arr + N);
	int l = 1, r = N, ans = -1;
	while (l <= r)
	{
		int m = l + r >> 1;
		lli cur = 0;
		for (int i = 0; i < N; ++i)
		{
			cur += max(0, arr[i] - i / m);
		}
		if (cur >= M) { ans = m; r = m - 1; }
		else l = m + 1;
	}
	cout << ans;
}
