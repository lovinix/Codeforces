#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		switch (N)
		{
		case 1:
			cout << 0;
			break;
		case 2:
			cout << M;
			break;
		default :
			cout << 2 * M;
		}
		cout << "\n";
	}
}