#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> arr[i];
	int ans;
	for (int i = N; i > 0; --i)
	{
		if (arr[i] == 0) { ans = i; break; }
	}
	for (int i = N; i > 0; --i)
	{
		if (arr[i] == 1) { ans = min(i, ans); break; }
	}
	cout << ans;
}