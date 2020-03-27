#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		int l = N - 2, r = N - 1, k = 1, cur = 1;
		while (k + cur <= K)
		{
			l--; k += cur++;
		}
		while (k < K)
		{
			r--; k++;
		}
		for (int i = 0; i < N; ++i)
		{
			if (i == l || i == r) cout << 'b';
			else cout << 'a';
		}
		cout << "\n";
	}
}