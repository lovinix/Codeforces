#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[300'010];

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
		for (int i = 0, v = 0, f = 1; i < N; ++i)
		{
			if (f == 1)
			{
				if (v <= A[i]) {}
				else
				{
					v = min(v - 2, A[i]); f = -1;
				}
			}
			else
			{
				if (v >= A[i]) { v = A[i]; }
				else { }
			}
			if (v < 0) { goto next; }
			v += f;
		}
		cout << "YES\n"; continue;
	next:;
		for (int i = N-1, v = 0, f = 1; i >= 0; --i)
		{
			if (f == 1)
			{
				if (v <= A[i]) {}
				else
				{
					v = min(v - 2, A[i]); f = -1;
				}
			}
			else
			{
				if (v >= A[i]) { v = A[i]; }
				else { }
			}
			if (v < 0) { cout << "NO\n"; goto next2; }
			v += f;
		}
		cout << "YES\n";
	next2:;
	}
}