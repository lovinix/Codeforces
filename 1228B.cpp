#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

const int MOD = 1e9 + 7;
int h, w, arr[1010][1010];

lli po(lli a, int b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> h >> w;
	for (int i = 0; i < h; ++i)
	{
		int t; cin >> t;
		for (int j = 0; j < t; ++j)
			arr[i][j] = 1;
		arr[i][t] = -1;
	}
	for (int j = 0; j < w; ++j)
	{
		int t; cin >> t;
		for (int i = 0; i < t; ++i)
		{
			if (arr[i][j] == -1) { cout << 0; return 0; }
			arr[i][j] = 1;
		}
		if (arr[t][j] == 1) { cout << 0; return 0; }
		arr[t][j] = -1;
	}
	int cnt = 0;
	for (int i = 0; i < h; ++i)
		for (int j = 0; j < w; ++j)
			if (!arr[i][j]) ++cnt;
	cout << po(2, cnt);
}

lli po(lli a, int b)
{
	if (!b) return 1;
	if (b == 1) return a;
	if (b & 1) return (a * po((a * a) % MOD, b / 2)) % MOD;
	else return po((a * a) % MOD, b / 2) % MOD;
}