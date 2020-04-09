#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M;
char ans[110][110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		if (N % 2 && M % 2)
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < M; ++j)
				{
					cout << ((i + j) % 2 ? 'W' : 'B');
				}
				cout << '\n';
			}
		}
		else
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j < M; ++j)
				{
					cout << ((i + j == 0 || (i + j) % 2) ? 'B' : 'W');
				}
				cout << '\n';
			}
		}
	}
}