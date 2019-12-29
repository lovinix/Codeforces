#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N;
pii arr[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i].first;
			arr[i].second = i + 1;
		}
		for (int i = 0; i < N - 1; ++i)
		{
			if ( abs(arr[i + 1].first - arr[i].first) > abs(arr[i + 1].second - arr[i].second))
			{
				cout << "YES\n" << arr[i].second << " " << arr[i + 1].second << "\n";
				goto next;
			}
		}
		cout << "NO\n";
	next:;
	}
}