#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, P, ans = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> P;
	for (int i = 1; i <= 31; ++i)
	{
		int tmp = N - i * P;
		if (tmp < i) continue;
		int cnt = 0;
		while (tmp)
		{
			if (tmp & 1) ++cnt;
			tmp >>= 1;
		}
		if (cnt > i) continue;
		ans = min(ans, i);
	}
	cout << (ans == INT_MAX ? -1 : ans);
}