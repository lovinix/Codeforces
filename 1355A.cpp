#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli A, K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A >> K;
		for (int i = 1; i < K; ++i)
		{
			lli mx = -1, mn = 10, tmp = A;
			while (tmp)
			{
				mx = max(tmp % 10, mx);
				mn = min(tmp % 10, mn);
				tmp /= 10;
			}
			if (mn == 0) { cout << A << "\n"; goto next; }
			A += mx * mn;
		}
		cout << A << "\n";
	next:;
	}
}