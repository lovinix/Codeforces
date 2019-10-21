#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[100'010], x, y;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = N - 1, j = 0; i >= j; --i, ++j)
	{
		if (i == j) x += arr[i];
		else
		{
			x += arr[i];
			y += arr[j];
		}
	}
	cout << x * x + y * y;
}