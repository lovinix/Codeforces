#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; ++i)
			cin >> A[i];
		if (N == 1 && A[1] % 2) { cout << "-1\n"; continue; }
		for (int i = 1; i <= N; ++i)
		{
			if (A[i] % 2 == 0) { cout << "1\n" << i << "\n"; goto next; }
		}
		cout << "2\n1 2\n";
	next:;
	}
}