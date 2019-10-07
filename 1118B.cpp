#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	int b[2]{ 0 };
	int a[2]{ 0 };
	for (int i = 1; i <= N; ++i)
		a[i & 1] += arr[i];
	int ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		a[i & 1] -= arr[i];
		b[(i - 1) & 1] += arr[i - 1];
		if (b[0] + a[1] == b[1] + a[0]) ++ans;
	}
	cout << ans;
}