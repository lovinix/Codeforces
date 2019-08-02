#include <bits/stdc++.h>
#define INF 2'000'000'000
using namespace std;

int arr[200000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	fill(arr, arr + 200000, INF);
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i + 100];
	}
	for (int i = 100; i < 100 + n; ++i)
	{
		for (int j = i - 1; j >= i - x; --j)
		{
			if (arr[j] <= arr[i])
				goto end;
		}
		for (int j = i + 1; j <= i + y; ++j)
		{
			if (arr[j] <= arr[i])
				goto end;
		}
		cout << i - 99;
		return 0;
	end:;
	}
}