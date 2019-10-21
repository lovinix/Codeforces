#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, M, even, odd;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		odd = 0, even = 0;
		lli ans = 0;
		for (int i = 0; i < N; ++i)
		{
			int x; cin >> x;
			if (x & 1) ++odd;
			else ++even;
		}
		cin >> M;
		for (int i = 0; i < M; ++i)
		{
			int x; cin >> x;
			if (x & 1) ans += odd;
			else ans += even;
		}
		cout << ans << "\n";
	}
}