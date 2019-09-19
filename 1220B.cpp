#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[1001][1001], ans[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= N; ++j)
			cin >> arr[i][j];
	ans[1] = sqrt(arr[1][2] * arr[1][3] / arr[2][3]);
	for (int i = 2; i <= N; ++i)
	{
		ans[i] = arr[i - 1][i] / ans[i - 1];
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}