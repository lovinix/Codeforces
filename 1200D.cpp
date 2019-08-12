#include <bits/stdc++.h>
using namespace std;

int n, k, ans, tr, tc;
int psr[2001][2001], psc[2001][2001], r[2001], c[2001], res[2001][2001];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
	{
		cin >> s;
		for (int j = 1; j <= n; ++j)
		{
			psr[i][j] = psr[i][j - 1] + (s[j - 1] == 'B');
			psc[i][j] = psc[i - 1][j] + (s[j - 1] == 'B');
			r[i] += s[j - 1] == 'B';
			c[j] += s[j - 1] == 'B';
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		if (r[i] == 0) ++ans;
		if (c[i] == 0) ++ans;
	}
	for (int i = 1; i + k <= n+1; ++i)
	{
		for (int j = 1; j + k <= n+1; ++j)
		{
			if (j == 1)
			{
				tc = 0;
				for (int z = j; z < k + j; ++z)
				{
					if (c[z]!=0 && psc[i + k - 1][z] - psc[i - 1][z] == c[z]) tc++;
				}
				res[i][j] = tc;
			}
			else
			{
				if (c[j-1]!=0 && psc[i + k - 1][j - 1] - psc[i - 1][j - 1] == c[j - 1]) --tc;
				if (c[j+k-1]!=0 && psc[i + k - 1][j + k - 1] - psc[i - 1][j + k - 1] == c[j + k - 1]) ++tc;
				res[i][j] = tc;
			}
		}
	}
	for (int j = 1; j + k <= n+1; ++j)
	{
		for (int i = 1; i + k <= n+1; ++i)
		{
			if(i==1)
			{
				tr = 0;
				for(int z=i;z<k+i;++z)
				{
					if (r[z]!=0 && psr[z][j + k - 1] - psr[z][j - 1] == r[z]) ++tr;
				}
				res[i][j] += tr;
			}
			else
			{
				if (r[i-1]!=0 && psr[i - 1][j + k - 1] - psr[i - 1][j - 1] == r[i - 1]) --tr;
				if (r[i+k-1]!=0 && psr[i + k - 1][j + k - 1] - psr[i + k - 1][j - 1] == r[i + k - 1]) ++tr;
				res[i][j] += tr;
				
			}
		}
	}
	int mx = -1;
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			mx = max(mx, res[i][j]);
	cout << ans + mx;
}
