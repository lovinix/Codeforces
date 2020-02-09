#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A[100'010], B[32];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < 32; ++j)
		{
			B[j] += A[i] >> j & 1;
		}
	}
	int ans = 0, idx = -1;
	for (int i = 0; i < N; ++i)
	{
		int cur = 0;
		for (int j = 0; j < 32; ++j)
		{
			if ((A[i] >> j & 1) and B[j] == 1)
				cur += 1 << j;
		}
		if (ans <= cur) { ans = cur; idx = i; }
	}
	cout << A[idx] << " ";
	for (int i = 0; i < N; ++i)
	{
		if (i == idx) continue;
		cout << A[i] << " ";
	}
}