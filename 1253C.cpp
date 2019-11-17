#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M;
lli arr[200'010], ans[200'010], psum[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	for (int i = 1; i <= N; ++i)
		psum[i] = psum[i - 1] + arr[i - 1];
	for (int i = 1; i <= M; ++i)
	{
		ans[i] = psum[i];
	}
	for (int i = M + 1; i <= N; ++i)
		ans[i] = psum[i] + ans[i - M];
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";
}