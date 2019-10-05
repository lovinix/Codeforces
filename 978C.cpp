#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M;
lli arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		arr[i] += arr[i - 1];
	}
	while (M--)
	{
		lli b; cin >> b;
		int idx = lower_bound(arr, arr + N + 1, b) - arr;
		cout << idx << " " << b - arr[idx - 1] << "\n";
	}
}