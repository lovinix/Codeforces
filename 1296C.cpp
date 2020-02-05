#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N;
string s;
multimap<pii, int> mm;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> s;
		mm.clear();
		int r = 0, c = 0;
		mm.insert({ { 0,0 }, 0 });
		for (int i = 1; i <= N; ++i)
		{
			if (s[i-1] == 'L') c--;
			if (s[i-1] == 'R') c++;
			if (s[i-1] == 'U') r--;
			if (s[i-1] == 'D') r++;
			mm.insert({ {r,c},i });
		}
		pii ans = { 0,INT_MAX };
		r = 0, c = 0;
		for (int i = 1; i <= N; ++i)
		{
			mm.erase(mm.lower_bound({ r,c }));
			if (mm.count({ r,c }))
			{
				int idx = mm.lower_bound({ r,c })->second;
				if (ans.second - ans.first > idx - i) { ans = { i,idx }; }
			}
			if (s[i-1] == 'L') c--;
			if (s[i-1] == 'R') c++;
			if (s[i-1] == 'U') r--;
			if (s[i-1] == 'D') r++;
		}
		if (ans.second == INT_MAX) cout << "-1\n";
		else cout << ans.first << " " << ans.second << "\n";
	}
}