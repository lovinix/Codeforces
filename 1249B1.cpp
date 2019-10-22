#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N, arr[200'010], dp[200'010], v[200'010];

int recv(int u, int cnt);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		for (int i = 0; i <= N; ++i)
		{
			dp[i] = -1;
			v[i] = 0;
		}
		for (int i = 1; i <= N; ++i)
			cin >> arr[i];
		for (int i = 1; i <= N; ++i)
			cout << recv(i, 0) << " ";
		cout << "\n";
	}
}

int recv(int u, int cnt)
{
	if (dp[u] != -1) return dp[u];
	if (v[u]) return dp[u] = cnt;
	v[u] = 1;
	return dp[u] = recv(arr[u], cnt + 1);
}