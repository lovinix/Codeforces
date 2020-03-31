#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, a, b, c, d, X, Y, X1, Y1, X2, Y2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b >> c >> d;
		cin >> X >> Y >> X1 >> Y1 >> X2 >> Y2;
		if (a > b) {
			a -= b; b = 0; if (X - a < X1) { cout << "NO\n"; continue; }
		}
		else if (a < b)
		{
			b -= a; a = 0; if (X + b > X2) { cout << "NO\n"; continue; }
		}
		else
		{
			if (a != 0 && X1 == X && X2 == X) { cout << "NO\n"; continue; }
		}
		if (c > d)
		{
			c -= d; d = 0; if (Y - c < Y1) { cout << "NO\n"; continue; }
		}
		else if (c < d)
		{
			d -= c; if (Y + d > Y2) { cout << "NO\n"; continue; }
		}
		else
		{
			if (c != 0 && Y1 == Y && Y2 == Y) { cout << "NO\n"; continue; }
		}
		cout << "YES\n";
	}
}