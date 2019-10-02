#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N, sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		sum = 0;
		for (int i = 0; i < N; ++i)
		{
			int t; cin >> t;
			sum += t;
		}
		cout << (sum % N ? (sum / N + 1) : (sum / N)) << "\n";
	}
}