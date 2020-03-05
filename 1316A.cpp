#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		int dif = M - A[0];
		for (int i = 1; i < N; ++i)
		{
			int mn = min(dif, A[i]);
			A[i] -= mn;
			dif -= mn;
		}
		cout << M - dif << "\n";
	}
}