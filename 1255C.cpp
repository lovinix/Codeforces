#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, ans[100'010];
set<int> arr[100'010];
vector<int> lst[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <=N-2; ++i)
	{
		int a, b, c;
		cin >> a >> b >> c;
		arr[i].emplace(a);
		arr[i].emplace(b);
		arr[i].emplace(c);
		lst[a].emplace_back(i);
		lst[b].emplace_back(i);
		lst[c].emplace_back(i);
	}
	for (int i = 1; i <= N; ++i)
	{
		if (lst[i].size() == 1)
		{
			if (ans[1] == 0) { ans[1] = i; break; }
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (lst[i].size() == 2)
		{
			for (auto& idx : lst[i])
			{
				if (arr[idx].count(ans[1])) { ans[2] = i; goto next; }
			}
		}
	}
next:;
	for (int i = 2; i < N; ++i)
	{
		for (auto& idx : lst[ans[i]])
		{
			if (arr[idx].count(ans[i]) && arr[idx].count(ans[i - 1]))
			{
				for (int v : arr[idx]) ans[i + 1] ^= v;
				ans[i + 1] = ans[i + 1] ^ ans[i] ^ ans[i - 1];
				arr[idx].clear();
				break;
			}
		}
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}