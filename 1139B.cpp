#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli cur, ans;
int N, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	cur = 1e10;
	for (int i = N - 1; i >= 0; --i)
	{
		cur = min(max(0LL,cur - 1), arr[i]*1LL);
		ans += cur;
	}
	cout << ans;
}