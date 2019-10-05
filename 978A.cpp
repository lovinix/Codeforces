#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[60], bef[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		if (bef[arr[i]]) arr[bef[arr[i]]] = 0;
		bef[arr[i]] = i;
	}
	int cnt = 0;
	for (int i = 1; i <= N; ++i)
		if (arr[i]) cnt++;
	cout << cnt << "\n";
	for (int i = 1; i <= N; ++i)
	{
		if (arr[i]) cout << arr[i] << " ";
	}
}