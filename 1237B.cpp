#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010], f[100'010], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	int idx = 0;
	for (int i = 0; i < N; ++i)
	{
		int t; cin >> t;
		if (t == arr[idx])
			++idx;
		else
		{
			++ans;
			f[t] = 1;
		}
		while (f[arr[idx]]) ++idx;
	}
	cout << ans;
}