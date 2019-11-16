#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t; cin >> t;
		a += t;
	}
	for (int i = 0; i < N; ++i)
	{
		int t; cin >> t;
		b += t;
	}
	if (a >= b) cout << "YES";
	else cout << "NO";
}