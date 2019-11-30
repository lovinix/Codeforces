#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
string arr[10];
map<string, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		m.clear();
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
			m[arr[i]]++;
		}
		for (int i = 0; i < N; ++i)
		{
			if (m[arr[i]] <= 1) continue;
			else
			{
				for (int j = '0'; i <= '9'; ++j)
				{
					string tmp = arr[i];
					tmp[0] = j;
					if (!m[tmp]) { ++ans; m[tmp]++; m[arr[i]]--; arr[i] = tmp; break; }
				}
			}
		}
		cout << ans << '\n';
		for (int i = 0; i < N; ++i)
			cout << arr[i] << "\n";
	}
}