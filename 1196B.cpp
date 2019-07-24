#include <bits/stdc++.h>
using namespace std;

int n, arr[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		int od=0;
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			od += (arr[i] & 1);
		}
		if (od < k || (od - k) % 2 == 1)
		{
			cout << "NO" << "\n";
			continue;
		}
		cout << "YES\n";
		int r = od - k + 1;
		int i = 0, cnt = 0;
		for (; cnt < r; ++i)
			cnt += (arr[i] & 1);
		cout << i << " ";
		for (; cnt<od-1 ; ++i)
		{
			if (arr[i] & 1)
			{
				cout << i + 1 << " ";
				++cnt;
			}
		}
		cout << n << "\n";
	}
}