#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		if (A < B)
		{
			if ((B - A) & 1) cout << 1 << "\n";
			else cout << "2\n";
		}
		else if (A > B)
		{
			if ((A - B) & 1) cout << "2\n";
			else cout << "1\n";
		}
		else cout << "0\n";
	}
}