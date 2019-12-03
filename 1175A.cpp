#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli N, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		lli cnt = 0;
		while (N)
		{
			if (N % K) { cnt += N % K; N -= N % K; }
			else { cnt++; N /= K; }
		}
		cout << cnt << "\n";
	}
}