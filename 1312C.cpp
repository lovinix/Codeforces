#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, K, cnt[110];
lli A[40];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < N; ++i)
		{
			int c = 0;
			lli M = 1;
			while (M < A[i]) { M *= K; c++; }
			while (A[i])
			{
				cnt[c] += A[i] / M;
				A[i] %= M;
				M /= K;
				c--;
			}
		}
		for (int i = 0; i <= 100; ++i)
			if (cnt[i] > 1) { cout << "NO\n"; goto next; }
		cout << "YES\n";
	next:;
	}
}