#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		int q = N / K;
		int r = N % K;
		if (r > K / 2) r = K / 2;
		cout << q * K + r << '\n';
	}
}