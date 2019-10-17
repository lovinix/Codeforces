#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, f1, f2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	while (N--)
	{
		int t; cin >> t;
		if (t % 2)
		{
			cout << t / 2 + (t > 0 ? f1 : -f2) << "\n";
			(t > 0 ? f1 : f2) ^= 1;
		}
		else
			cout << t / 2 << "\n";
	}
}