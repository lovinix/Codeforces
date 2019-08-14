#include <bits/stdc++.h>
using namespace std;

int n, arr[150'011], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;++i)
	{
		int t; cin >> t;
		arr[t]++;
	}
	bool f = 0;
	int cnt = 0;
	for(int i=1,j=0;i<=150010;++i)
	{
		if(arr[i])
		{
			if (f == 0) { j = i; f = 1; cnt = 0; }
			cnt += arr[i];
		}
		else
		{
			if(f==1)
			{
				ans += i - j; cnt -= i - j;
				if (cnt && j-1!=0 && arr[j - 1] == 0) { arr[j - 1]++; cnt--; ++ans; }
				if (cnt && arr[i] == 0) { arr[i]++; cnt--; ++ans; }
				f = 0;
			}
		}
	}
	cout << ans;
	
}
