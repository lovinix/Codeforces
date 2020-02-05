#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A[210];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	memset(A, -1, sizeof A);
	for (int i = N - 1; i >= 0; --i)
	{
		if (A[i] == -1)
		{
			A[i] = 0;
			for (int j = i - 1; j >= 0; --j)
			{
				if (s[j] > s[i]) A[j] = !A[i];
			}
		}
		else
		{
			for (int j = i - 1; j >= 0; --j)
			{
				if (s[j] > s[i] and A[j] == A[i]) { cout << "NO"; return 0; }
			}
		}
	}
	cout << "YES\n";
	for (int i = 0; i < N; ++i)
		cout << A[i];
}