#include <bits/stdc++.h>
using namespace std;

int q, n, cnt[200'001], arr[200'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while(q--)
	{
		cin >> n;
		for(int i=0;i<n;++i)
		{
			int t;
			cin >> t;
			cnt[arr[t]]--;
			arr[t]++;
			cnt[arr[t]]++;
		}
		int sz = 0, tmp = 0;
		for(int i=n;i>0;--i)
		{
			if (cnt[i]) { sz += i; tmp += cnt[i] - 1; }
			else if (tmp) { sz += i; tmp--; }
		}
		cout << sz << "\n";
		for (int i = 0; i <= n; ++i)
			cnt[i] = 0, arr[i] = 0;
	}

}
