#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[100'010], B[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < N; ++i)
			cin >> B[i];
		int f = 0, dif = 0;
		for (int i = 0; i < N; ++i)
		{
			if(f==0 && A[i]!=B[i])
			{
				f = 1; dif = A[i] - B[i];
				if (dif > 0) { cout << "NO\n"; goto next; }
			}
			else if (f == 1 && A[i] == B[i])
			{
				f = 2;
			}
			else if (f == 2 && A[i] != B[i])
			{
				cout << "NO\n"; goto next;
			}
			else if (f == 1 && A[i] != B[i])
			{
				if (A[i] - B[i] != dif)
				{
					cout << "NO\n"; goto next;
				}
			}
		}
		cout << "YES\n";

	next:;
	}
}