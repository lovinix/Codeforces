#include <bits/stdc++.h>
using namespace std;

int n, m, a[201], b[201];
set<int> as, bs;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for(int i=0;i<n;++i)
	{
		cin >> a[i];
		as.insert(a[i]);
	}
	cin >> m;
	for(int i=0;i<m;++i)
	{
		cin >> b[i];
		bs.insert(b[i]);
	}
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(as.count(a[i]+b[j])+bs.count(a[i]+b[j])==0)
			{
				cout << a[i] << " " << b[j];
				return 0;
			}
		}
	}
}
