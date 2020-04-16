#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string A[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 9; ++i)
			cin >> A[i];
		for (int i = 0, j = 0; i < 9; ++i)
		{
			A[i][j] = A[i][j] == '1' ? '2' : '1';
			j = (j + 3) % 8;
			if (!j) j = 8;
		}
		for (int i = 0; i < 9; ++i)
			cout << A[i] << "\n";
	}
}