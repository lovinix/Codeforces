#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[110], P[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
			cin >> A[i];
		memset(P, 0, sizeof P);
		for (int i = 1; i <= M; ++i)
		{
			int p; cin >> p;
			P[p] = 1;
		}
		for (int i = 1; i < N; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (A[j] > A[j + 1])
				{
					if (P[j]) swap(A[j], A[j + 1]);
					else { cout << "NO\n"; goto next; }
				}
			}
		}
		cout << "YES\n";
	next:;

	}
}