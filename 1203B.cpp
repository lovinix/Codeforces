#include <bits/stdc++.h>
using namespace std;

int q, n, arr[10'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> q;
	while(q--)
	{
		cin >> n;
		memset(arr, 0, sizeof arr);
		int mn = 100'000 , mx = -1;
		for(int i=0;i<4*n;++i)
		{
			int t; cin >> t;
			mn = min(mn, t);
			mx = max(mx, t);
			arr[t]++;
		}
		if (arr[mn] < 2 || arr[mx] < 2 || (mn == mx && arr[mn] < 4)) { cout << "NO\n"; continue; }
		int sz = mn * mx;
		arr[mn] -= 2; arr[mx] -= 2;
		for(int i=mn; i<=mx;++i)
		{
			while(arr[i])
			{
				if(arr[i]%1)
				{
					cout << "NO\n"; goto end;
				}
				if(sz%i || arr[sz/i]<2)
				{
					cout << "NO\n"; goto end;
				}
				arr[i] -= 2; arr[sz / i] -= 2;
			}
		}
		cout << "YES\n";
	end:;
	}
}
