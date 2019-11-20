#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, R, C, K, tot;
string arr[110], ans[110];
string str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789 ";


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> R >> C >> K;
		tot = 0;
		for (int i = 0; i < R; ++i)
		{
			cin >> arr[i];
			ans[i].resize(C);
			for (auto& c : arr[i]) if (c == 'R') tot++;
		}
		int cnt = tot / K, rem = tot % K, cur = 0, idx = 0;
		for (int i = 0; i < R; ++i)
		{
			for (int j = (i & 1 ? C - 1 : 0); (i & 1 ? j >= 0 : j < C); (i & 1 ? --j : ++j))
			{
				if (cur == cnt + (rem ? 1 : 0))
				{
					idx++; cur = 0;
					if (rem) rem--;
				}
				ans[i][j] = str[idx];
				if (arr[i][j] == 'R') cur++;
			}
		}
		for (int i = 0; i < R; ++i)
			for (int j = 0; j < C; ++j)
				if (ans[i][j] == str[K]) ans[i][j] = str[K - 1];
		for (int i = 0; i < R; ++i)
			cout << ans[i] << "\n";
	}
}