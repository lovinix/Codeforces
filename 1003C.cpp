#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K;
double arr[5010], ans = -1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i + K - 1 < N; ++i)
	{
		double sum = 0;
		for (int j = i; j < i + K - 1; ++j) sum += arr[j];
		for (int j = i + K - 1; j < N; ++j)
		{
			sum += arr[j];
			ans = max(sum / (j - i + 1), ans);
		}
	}
	cout << fixed << setprecision(10) << ans;
}