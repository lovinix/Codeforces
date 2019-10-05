#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, W, arr[1010];
lli mn, mx;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> W;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	lli cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		cnt += arr[i];
		mn = min(mn, cnt);
		mx = max(mx, cnt);
	}
	lli dif = mx - mn;
	if (dif > W) { cout << 0; return 0; }
	cout << W - dif + 1;
}