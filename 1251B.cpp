#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N, arr[51], sum[2];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		memset(sum, 0, sizeof sum);
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin >> s;
			arr[i] = s.length();
			for (auto& c : s)
				sum[c - '0']++;
		}
		int ans = 0;
		sort(arr, arr + N, [](int a, int b) {return ((a & 1) == (b & 1)) ? a < b : (a & 1 ? 0 : 1); });
		for (int i = 0; i < N; ++i)
		{
			if (arr[i] & 1) { ++ans; continue; }
			int& mx = sum[0] > sum[1] ? sum[0] : sum[1];
			int& mn = sum[0] > sum[1] ? sum[1] : sum[0];
			if (mx >= arr[i]) { mx -= arr[i]; ++ans; continue; }
			int c = arr[i] - (mx - (mx & 1));
			if (mn >= c) { mx = 0; mn -= c; ++ans; continue; }
		}
		cout << ans << "\n";
	}
}