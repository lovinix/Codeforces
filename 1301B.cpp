#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for_each_n(A, N, [](int& v) {cin >> v; });
		int mx = 1e9, mn = 0;
		for (int i = 0; i < N; ++i)
		{
			if (A[i] != -1) continue;
			if (i != 0)
			{
				mx = min(mx, A[i - 1] + );
			}
		}
	}
}