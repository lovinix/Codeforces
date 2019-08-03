#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;

int T, n, m, cnt;
bool used[300001];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> n >> m;
		memset(used, 0, sizeof(used));
		cnt = 0;
		ans.clear();
		for (int i = 1; i <= m; ++i)
		{
			int u, v;
			cin >> u >> v;
			if (!used[u] && !used[v])
			{
				ans.emplace_back(i);
				used[u] = used[v] = 1;
				++cnt;
			}
		}
		if (cnt >= n)
		{
			cout << "Matching\n";
			for (int i = 0; i < n; ++i)
				cout << ans[i] << " ";
			cout << "\n";
			continue;
		}
		cnt = 0; ans.clear();
		for (int i = 1; i <= 3*n; ++i)
		{
			if (!used[i]) { ++cnt; ans.emplace_back(i); }
		}
		if (cnt >= n)
		{
			cout << "IndSet\n";
			for (int i = 0; i < n; ++i)
				cout << ans[i] << " ";
			cout << "\n";
			continue;
		}
		cout << "Impossible\n";
	}
}