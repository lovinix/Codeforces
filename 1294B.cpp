#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N;
pii A[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i].first >> A[i].second;
		}
		sort(A, A + N);
		int cx = 0, cy = 0;
		string ans;
		for (int i = 0; i < N; ++i)
		{
			auto [x, y] = A[i];
			if (cx > x || cy > y) { cout << "NO\n"; goto next; }
			while (cx < x) { ans += 'R'; cx++; }
			while (cy < y) { ans += 'U'; cy++; }
		}
		cout << "YES\n" << ans << '\n';
	next:;
	}
}