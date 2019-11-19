#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> a >> b;
		int cnt;
		if (a == b) { cout << "0\n"; continue; }
		if (a > b) 
		{
			int dif = a - b;
			cnt = dif / 5;
			dif %= 5;
			cnt += dif / 2;
			dif %= 2;
			cnt += dif;
		}
		else
		{
			int dif = b - a;
			cnt = dif / 5;
			dif %= 5;
			cnt += dif / 2;
			dif %= 2;
			cnt += dif;
		}
		cout << cnt << '\n';
	}
}