#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K1, K2, A[110],B[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K1 >> K2;
		for (int i = 0; i < K1; ++i)
			cin >> A[i];
		for (int i = 0; i < K2; ++i)
			cin >> B[i];
		for (int i = 0; i < K1; ++i)
		{
			if (A[i] == N) { cout << "YES\n"; goto next; }
		}
		for (int i = 0; i < K2; ++i)
		{
			if (B[i] == N) { cout << "NO\n"; goto next; }
		}
	next:;
	}
}