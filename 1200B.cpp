#include <bits/stdc++.h>
using namespace std;

int n, m, k, arr[1'000'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		cin >> n >> m >> k;
		for (int i = 0; i < n; ++i)
			cin >> arr[i];
		for(int i=0;i<n-1;++i)
		{
			int lo = max(arr[i + 1] - k, 0);
			if(lo>arr[i])
			{
				int dif = lo - arr[i];
				if (dif > m) { cout << "NO\n"; goto end; }
				else
				{
					m -= dif;
				}
			}
			else
			{		
				m += arr[i] - lo;
			}
		}
		cout << "YES\n";
	end:;
	}
}
