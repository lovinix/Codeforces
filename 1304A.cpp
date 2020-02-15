#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, X, Y, A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> X >> Y >> A >> B;
		if ((Y - X) % (A + B)) { cout << "-1\n"; }
		else cout << (Y - X) / (A + B) << "\n";
	}
}