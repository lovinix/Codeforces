#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, k;
lli arr[200'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	sort(arr, arr + n);
	int cur = 1, len = 1;
	while(n/2+cur<n && k>0)
	{
		if(arr[n/2]<arr[n/2+cur])
		{
			lli dif = arr[n / 2 + cur] - arr[n / 2];
			if(dif*len<=k)
			{
				k -= dif * len;
				len++; cur++;
				arr[n / 2] += dif;
			}
			else
			{
				arr[n / 2] += k / len;
				k = 0;
				break;
			}
		}
		else
		{
			len++; cur++;
		}
	}
	if (k)
		arr[n / 2] += k / len;
	cout << arr[n / 2];
}