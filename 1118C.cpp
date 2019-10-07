#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[500], cnt[1001], ans[21][21];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N * N; ++i)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	int od = 0;
	for (int i = 1; i <= 1000; ++i)
	{
		if (cnt[i] & 1) ++od;
	}
	if (od)
	{
		if (!(od == 1 && (N & 1)))
		{
			cout << "NO\n"; return 0;
		}
	}
	for (int i = 0; i < N / 2; ++i)
	{
		for (int j = 0; j < N / 2; ++j)
		{
			for (int k = 0; k < N * N; ++k)
			{
				if (cnt[arr[k]] >= 4)
				{
					ans[i][j] = ans[N - i - 1][N - j - 1] = ans[i][N - j - 1] = ans[N - i - 1][j] = arr[k];
					cnt[arr[k]] -= 4;
					goto next;
				}
			}
			cout << "NO"; return 0;
		next:;
		}
	}
	if (N & 1)
	{
		for (int i = 0; i < N / 2; ++i)
		{
			for (int k = 0; k < N * N; ++k)
			{
				if (cnt[arr[k]] >= 2)
				{
					ans[i][N / 2] = ans[N - i - 1][N / 2] = arr[k];
					cnt[arr[k]] -= 2;
					goto next2;
				}
			}
			cout << "NO"; return 0;
		next2:;
		}
		for (int j = 0; j < N / 2; ++j)
		{
			for (int k = 0; k < N * N; ++k)
			{
				if (cnt[arr[k]] >= 2)
				{
					ans[N / 2][j] = ans[N / 2][N - j - 1] = arr[k];
					cnt[arr[k]] -= 2;
					goto next3;
				}
			}
			cout << "NO"; return 0;
		next3:;
		}
		for (int k = 0; k < N * N; ++k)
			if (cnt[arr[k]] & 1) { ans[N / 2][N / 2] = arr[k]; break; }
	}
	cout << "YES\n";
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}

}