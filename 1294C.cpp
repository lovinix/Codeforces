#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int tmp = N;
		ans.clear();
		for (int i = 2; i * i <= N; ++i)
		{
			if (tmp % i == 0) { ans.emplace_back(i); tmp /= i; }
		}
		if (tmp > 1) ans.emplace_back(tmp);
		if (ans.size() < 3) { cout << "NO\n"; }
		else
		{
			for (int i = 3; i < ans.size(); ++i)
				ans[2] *= ans[i];
			if (ans[0] == ans[1] || ans[1] == ans[2] || ans[0] == ans[2]) { cout << "NO\n"; }
			else
			{
				cout << "YES\n";
				for (int i = 0; i < 3; ++i)
					cout << ans[i] << " ";
				cout << '\n';
			}
		}
	}
}