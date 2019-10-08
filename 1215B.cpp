#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, arr[200'010];
lli p, m, ans[2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	int cur = 0;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] < 0) cur ^= 1;
		if (cur) ++m;
		else ++p;
	}
	ans[0] = p; ans[1] = m;
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] < 0) { m--; swap(m, p); }
		else p--;
		ans[0] += p;
		ans[1] += m;
	}
	cout << ans[1] << " " << ans[0];
}