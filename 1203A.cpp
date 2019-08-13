#include <bits/stdc++.h>
using namespace std;

int q, n;
vector<int> arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> q;
	while (q--)
	{
		cin >> n;
		arr.clear();
		for (int i = 0; i < n; ++i)
		{
			int t;
			cin >> t;
			arr.push_back(t);
		}
		bool f = 1;
		for (int i = 0; i < n; ++i)
		{
			if(arr[(i+1)%n]%n!=(arr[i]+1)%n)
			{
				f = 0; break;
			}
		}
		if (f) { cout << "YES\n"; continue; }
		f = 1;
		for(int i=0;i<n;++i)
		{
			if(arr[(i+1)%n]%n!=(arr[i]-1)%n)
			{
				f = 0; break;
			}
		}
		if (f) { cout << "YES\n";}
		else { cout << "NO\n"; }

	}
}
