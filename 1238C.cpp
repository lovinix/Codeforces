#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, H, N, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> H >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		arr[N] = arr[N + 1] = 0;
		int cur = H, ans = 0;
		for (int i = 0; i < N - 1;)
		{
			if (cur <= 2) break;
			if (arr[i + 1] != cur - 1)
			{
				cur = arr[i + 1] + 1; continue;
			}
			if (arr[i + 2] == cur - 2)
			{
				i += 2; cur = arr[i]; continue;
			}
			++ans; ++i; cur = arr[i];
		}
		cout << ans << "\n";
	}
}