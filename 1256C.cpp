#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, D, arr[1010], ans[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> D;
	int sum = 0;
	for (int i = 1; i <= M; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	int cur = 0;
	for (int i = 1, r = N;i<=M; ++i)
	{
		if (r == sum)
		{
			++cur;
			while (cur <= N)
			{
				for (int k = 0; k < arr[i]; ++k)
					ans[cur+k] = i;
				cur += arr[i++];
			}
			goto end;
		}
		if (r - D - arr[i] + 1 < sum - arr[i])
		{
			int dif = r + 1 - sum;
			cur += dif;
			for (int j = 0; j < arr[i]; ++j)
				ans[cur + j] = i;
			cur += arr[i] - 1;
			sum -= arr[i];
			r -= dif + arr[i] - 1;
		}
		else
		{
			cur += D;
			for (int j = 0; j < arr[i]; ++j)
				ans[cur + j] = i;
			cur += arr[i] - 1;
			sum -= arr[i];
			r -= D + arr[i] - 1;
		}
	}
end:;
	if (cur + D <= N) { cout << "NO"; return 0; }
	else
	{
		cout << "YES\n";
		for (int i = 1; i <= N; ++i)
			cout << ans[i] << " ";
	}

}