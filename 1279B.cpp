#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int T, N, S;
lli arr[100'010], psum[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> S;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
			psum[i] = psum[i - 1] + arr[i];
		}
		if (psum[N] <= S) { cout << "0\n"; continue; }
		int l = 1, r = 2;
		lli sum = arr[1];
		while (r<=N && sum + arr[r] <= S) { sum += arr[r++]; }
		int len = r - l, ans = 0;
		for (int i = 1; i <= N; ++i)
		{
			while (r <= i) sum += arr[r++];
			sum += arr[i - 1];
			sum -= arr[i];
			while (r <= N && sum + arr[r] <= S) sum += arr[r++];
			if (sum<= S && r - l - 1 >= len) { len = r - l - 1; ans = i; }
		}
		cout << ans << "\n";
	}
}