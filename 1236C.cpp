#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, ans[301][301];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int r = 1, c = 1, d = 1;
	for (int i = 1; i <= N * N; ++i)
	{
		if (r == N + 1 && d == 1) { r = N; d = -1; ++c; }
		if (r == 0 && d == -1) { r = 1; d = 1; ++c; }
		ans[r][c] = i;
		r += d;
	}
	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= N; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}