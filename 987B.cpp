#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> y;
	if (x == y) { cout << "="; return 0; }
	double l = y * log(x);
	double r = x * log(y);
	if (l > r) cout << ">";
	else if (l < r) cout << "<";
	else cout << "=";
}