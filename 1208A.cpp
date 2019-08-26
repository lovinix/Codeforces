#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		int a, b, n;
		cin >> a >> b >> n;
		switch (n % 3)
		{
		case 0:
			cout << a;
			break;
		case 1:
			cout << b;
			break;
		case 2:
			cout << (a ^ b);
			break;
		}
		cout << "\n";
	}
}