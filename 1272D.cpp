#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[200'010], len[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	for (int i = 1; i <= N; ++i)
	{
		if (arr[i] > arr[i - 1])
			len[i] = len[i - 1] + 1;
		else
			len[i] = 1;
	}
	int ans = 0;
	for (int i = 1; i <= N; ++i)
		ans = max(ans, len[i]);
	for (int i = N; i > 0; --i)
	{
		if (i - len[i] - 1 > 0 && arr[i - len[i] - 1] < arr[i - len[i] + 1])
			ans = max(ans, len[i] + len[i - len[i] - 1]);
		if (len[i] > 1 && i - len[i] > 0 && arr[i - len[i]] < arr[i - len[i] + 2])
			ans = max(ans, len[i] - 1 + len[i - len[i]]);
	}
	cout << ans;
}