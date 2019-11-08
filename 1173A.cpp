#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int x, y, z;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> x >> y >> z;
	int dif = x - y;
	if (!z)
	{
		if (dif < 0) cout << '-';
		else if (dif == 0) cout << '0';
		else cout << '+';
	}
	else
	{
		if (dif + z < 0) cout << '-';
		else if (dif - z > 0) cout << '+';
		else cout << '?';
	}
}