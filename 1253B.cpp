#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010], cnt[1'000'010], tot;
vector<int> ans;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0, j=1; i < N; ++i,++j)
	{
		int& c = arr[i];
		if (c > 0)
		{
			if (cnt[c] || s.count(c)) { cout << "-1\n"; return 0; }
			++cnt[c];
			++tot;
		}
		else
		{
			if (cnt[-c] == 0) { cout << "-1\n"; return 0; }
			--cnt[-c];
			--tot;
			s.emplace(-c);
		}
		if (tot == 0) 
		{ 
			ans.emplace_back(j);
			j = 0;
			s.clear();
		}
	}
	if (tot || ans.empty()) { cout << "-1\n"; }
	else
	{
		cout << ans.size() << '\n';
		for (auto& i : ans) cout << i << " ";
	}
}