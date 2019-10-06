#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		int n; cin >> n;
		if (n == 1) { cout << "3\n"; continue; }
		if (n == 2) { cout << "2\n"; continue; }
		if (n == 3) { cout << "1\n"; continue; }
		int l, r, v;
		v = n / 2 + n % 2;
		l = (n / 2) / 2;
		r = ((n / 2) / 2) + (n / 2) % 2;
		if (l == 0)  v+=2;
		cout << v - (l + r) << "\n";
	}
}