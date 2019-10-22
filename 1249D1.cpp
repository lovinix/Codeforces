#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;

int N, K, cnt[210];
tu arr[210];
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int l, r; cin >> l >> r;
		arr[i] = { l,r,i + 1 };
	}
	sort(arr, arr + N, [](tu& t1, tu& t2)
		{
			auto& [l1, r1, i1] = t1;
			auto& [l2, r2, i2] = t2;
			return r1 == r2 ? l1 < l2 : r1 < r2;
		});
	for (int i = 0; i < N; ++i)
	{
		auto [l, r, idx] = arr[i];
		for (int j = l; j <= r; ++j)
		{
			if (cnt[j] >= K) { ans.emplace_back(idx); goto next; }
		}
		for (int j = l; j <= r; ++j) cnt[j]++;
	next:;
	}
	cout << ans.size() << "\n";
	for (auto& i : ans)
		cout << i << " ";
}