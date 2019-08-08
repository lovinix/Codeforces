#include <bits/stdc++.h>
using namespace std;

int dp[10][10][10][10], ans[10][10];
bool visit[10][10][10][10];

int recv(int a, int b, int c, int d);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string s;
	cin >> s;
	memset(dp, -1, sizeof(dp));
	for(int a=1;a<10;++a)
	{
		for(int b=1;b<10;++b)
		{
			for(int c=0;c<10;++c)
			{
				dp[a][b][c][(c + a) % 10] = 1;
				dp[a][b][c][(c + b) % 10] = 1;
			}
		}
	}
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if (i == 0 && j == 0) continue;
			for(int a=0;a<10;++a)
			{
				for (int b = 0; b < 10; ++b)
					dp[i][j][a][b] = recv(i, j, a, b);
			}
		}
	}
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if (i == 0 && j == 0) continue;
			for(int a=0;a<10;++a)
			{
				dp[i][j][a][a] = 123456789;
				for(int b=0;b<10;++b)
				{
					if (a == b) continue;
					dp[i][j][a][a] = min(dp[i][j][a][a], recv(i, j, a, b) + recv(i, j, b, a));
				}
			}
		}
	}
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			if (i == 0 && j == 0) { ans[i][j] = -1; continue; }
			int cur = 0;
			for(int idx=0;idx<s.length()-1;++idx)
			{
				int tmp = recv(i, j, s[idx] - '0', s[idx + 1] - '0');
				if (tmp >= 123456789) { ans[i][j] = -1; goto end; }
				cur += tmp-1;
			}
			ans[i][j] = cur;
		end:;
		}
	}
	for(int i=0;i<10;++i)
	{
		for(int j=0;j<10;++j)
		{
			cout << ans[i][j] << " ";
		}
		cout << "\n";
	}
}

int recv(int a,int b, int c, int d)
{
	if (dp[a][b][c][d] != -1) return dp[a][b][c][d];
	if (c == d) return 0;
	int ret = 123456789;
	if (visit[a][b][c][d]) return 123456789;
	visit[a][b][c][d] = true;
	ret = min(ret, recv(a, b, c, (d - a + 10) % 10) + 1);
	ret = min(ret, recv(a, b, c, (d - b + 10) % 10) + 1);
	return dp[a][b][c][d] = ret;
}