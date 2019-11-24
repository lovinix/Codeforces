#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N;
pii arr[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int l = 0, r = INT_MAX;
		for (int i = 0; i < N; ++i)
			cin >> arr[i].first >> arr[i].second;
		if (N == 1) { cout << "0\n"; goto next; }
		for (int i = 0; i < N; ++i)
		{
			l = max(l, arr[i].first);
			r = min(r, arr[i].second);
		}
		if (l <= r) { cout << "0\n"; }
		else cout << l - r << "\n";
	next:;
	}
}