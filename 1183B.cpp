#include <bits/stdc++.h>
using namespace std;

int q, n, k, arr[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> n >> k;
		int mn = 1e9, mx = -1;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			mn = min(arr[i], mn);
			mx = max(arr[i], mx);
		}
		if (mn + k < mx - k)  cout << "-1\n";
		else cout << mn + k << "\n";
	}
}