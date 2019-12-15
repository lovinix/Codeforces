#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int T, N, p[200'010];
lli sum, mx;
vector<pii> adj[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		sum = mx = 0;
		for (int i = 1; i < 2 * N; ++i)
		{
			int a, b, t;
			cin >> a >> b >> t;
			sum += t;
			mx = max(mx, (lli)t);
			adj[a].emplace_back(b, t);
			adj[b].emplace_back(a, t);
		}
		cout << sum - mx << " ";

	}
}

void dfs(int u)
{
	if(u!=1 && adj[u].size()==1)

}