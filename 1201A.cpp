#include <bits/stdc++.h>
using namespace std;

int n, m;
string arr[1001];
int sc[1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
		cin >> arr[i];
	for (int i = 0; i < m; ++i)
		cin >> sc[i];
	long long ans = 0;
	for(int i=0;i<m;++i)
	{
		int cnt[5]={0};
		for(int j=0;j<n;++j)
		{
			cnt[arr[j][i]-'A']++;
		}
		int mx = -1;
		for (int i = 0; i < 5; ++i)
			mx = max(mx, cnt[i]);
		ans+=mx* sc[i];
	}
	cout << ans;
}