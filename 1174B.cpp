#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	int o = 1, e = 1;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (arr[i] % 2 == 0) o = 0;
		else e = 0;
	}
	if (o || e) { for (int i = 0; i < N; ++i) cout << arr[i] << " "; }
	else
	{
		sort(arr, arr + N);
		for (int i = 0; i < N; ++i)
			cout << arr[i] << " ";
	}
}