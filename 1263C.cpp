#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T;
lli N;
set<lli> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		ans.clear();
		ans.emplace(0);
		for (lli i = 1; i * i <= N; ++i)
		{
			if (ans.count(i)) continue;
			if (ans.count(N / i)) continue;
			ans.emplace(N / i);
			ans.emplace(i);
		}
		cout << ans.size() << "\n";
		for (auto i : ans)
			cout << i << " ";
		cout << "\n";
	}
}