#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, ans[1010];
pii arr[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		arr[i].second = i;
		cin >> arr[i].first;
	}
	sort(arr, arr + N, [](pii& p1, pii& p2) {return p1.first > p2.first; });
	int sum = 0;
	for (int i = 0; i < N; ++i)
	{
		sum += arr[i].first * i + 1;
	}
	cout << sum << "\n";
	for (int i = 0; i < N; ++i)
		cout << arr[i].second + 1 << " ";

}