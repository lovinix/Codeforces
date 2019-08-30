#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int q;
lli n, m;
bool visit[10];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> n >> m;
		int t = m % 10, len = 0;
		lli sum = 0;
		vector<int> digit;
		memset(visit, 0, sizeof visit);
		while (!visit[t])
		{
			visit[t] = 1; ++len;
			digit.emplace_back(t);
			sum += t;
			t += m % 10;
			t %= 10;
		}
		lli z = n / m;
		lli ans = 0;
		ans += (z / len) * sum;
		for (int i = 0; i < z % len; ++i)
			ans += digit[i];
		cout << ans << "\n";
	}
}