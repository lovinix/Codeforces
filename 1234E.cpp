#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, arr[200'010], p1, cnt[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= M; ++i)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	for (int i = 1; i < M; ++i)
		p1 += abs(arr[i] - arr[i + 1]);
	cout << p1 << " ";
	for (int i = 2; i <= N; ++i)
	{
		p1 -= abs(arr[i - 1] - arr[i]);
		p1 -= abs(arr[i] - arr[i + 1]);
		p1 += arr[i - 1] == i ? 0 : arr[i - 1] < i ? arr[i - 1] : arr[i - 1] - 1;
		p1 += arr[i + 1] == i ? 0 : arr[i + 1] < i ? arr[i + 1] : arr[i + 1] - 1;
		cout << p1 << " ";
		p1 -= arr[i - 1] == i ? 0 : arr[i - 1] < i ? arr[i - 1] : arr[i - 1] - 1;
		p1 -= arr[i + 1] == i ? 0 : arr[i + 1] < i ? arr[i + 1] : arr[i + 1] - 1;
		p1 += abs(arr[i - 1] - arr[i]);
		p1 += abs(arr[i] - arr[i + 1]);
	}
}
