#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K, D, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K >> D;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		int l = 0, r = K, ans=INT_MAX;

		map<int, int> s;
		for (int i = 0; i < D - 1; ++i) s[arr[i]]++;
		for (int i = 0, j = D - 1; j < N; ++i, ++j)
		{
			s[arr[j]]++;
			ans = min(ans, (int)s.size());
			s[arr[i]]--;
			if (s[arr[i]] == 0) s.erase(arr[i]);
		}
	
		cout << ans << "\n";
	}
}