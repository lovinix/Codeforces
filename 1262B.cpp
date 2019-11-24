#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, arr[100'010], ans[100'010], v[100'010];
vector<int> vt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 1; i <= N; ++i) v[i] = 0, ans[i] = 0;
		vt.clear();
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		for (int i = 0; i < N; ++i)
		{
			if (!v[arr[i]]) { ans[i] = arr[i];  v[arr[i]] = 1; }
		}
		for (int i = 1; i <= N; ++i)
			if (!v[i]) vt.emplace_back(i);
		sort(vt.begin(), vt.end());
		reverse(vt.begin(), vt.end());
		for (int i = 0; i < N; ++i)
		{
			if (ans[i]) continue;
			if (vt.back() >= arr[i]) { cout << "-1"; goto next; }
			ans[i] = vt.back();
			vt.pop_back();
		}
		for (int i = 0; i < N; ++i)
			cout << ans[i] << " ";
	next:;
		cout << '\n';
	}
}