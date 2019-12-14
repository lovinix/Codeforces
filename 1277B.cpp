#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, arr[200'010];
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		s.clear();
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			while (arr[i] % 2 == 0)
			{
				if (s.count(arr[i])) break;
				s.emplace(arr[i]);
				ans++;
				arr[i] /= 2;
			}
		}
		cout << ans << "\n";
	}
}