#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, X, arr[100'010], ans = -1;
set<int> s1, s2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> X;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		if (s1.count(arr[i])) { cout << 0; return 0; }
		s1.emplace(arr[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		s1.erase(arr[i]);
		int tmp = arr[i] & X;
		if (s1.count(tmp)) { cout << 1; return 0; }
		if (s2.count(tmp)) { ans = 2; }
		s1.emplace(arr[i]);
		s2.emplace(tmp);
	}
	cout << ans;
}