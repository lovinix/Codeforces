#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[1'000'010], idx[1'000'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		idx[arr[i]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (idx[i] == i) continue;
		++cnt;
		swap(arr[idx[i]], arr[i]);
		swap(idx[i], idx[arr[idx[i]]]);
	}
	if (N & 1)
	{
		cout << (cnt & 1 ? "Petr" : "Um_nik");
	}
	else
	{
		cout << (cnt & 1 ? "Um_nik" : "Petr");
	}
}