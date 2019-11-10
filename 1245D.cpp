#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;
using pll = pair<lli, lli>;
int N, visit[2010];
lli cost[2010], wire[2010], ans;
pll co[2010];
vector<int> lst;
vector<pii> edge;

auto cmp = [](pll& t1, pll& t2) {return t1.second > t2.second; };
priority_queue<tu, vector<tu>, decltype(cmp)> pq(cmp);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> co[i].first >> co[i].second;
	int mn = INT_MAX, idx = -1;
	for (int i = 1; i <= N; ++i)
	{
		cin >> cost[i];
		if (mn >= cost[i]) { mn = cost[i]; idx = i; }
	}
	for (int i = 1; i <= N; ++i)
		cin >> wire[i];
	co[0] = { INT_MAX,INT_MAX };
	visit[idx] = 1;
	ans += mn;
	pq.emplace(idx, 0);
	while (!pq.empty())
	{
		auto [u,]
	}
	cout << ans << "\n" << lst.size() << "\n";
	for (auto& i : lst)
		cout << i << " ";
	cout << "\n" << edge.size() << "\n";
	for (auto& [u, v] : edge)
		cout << u << " " << v << "\n";
}

void dfs(int u, int p)
{
	visit[u] = 1;
	lli c = (abs(co[p].first - co[u].first) + abs(co[p].second - co[u].second)) * (wire[u] + wire[p]);
	if ( c > cost[u])
	{
		ans += cost[u];
		lst.emplace_back(u);
	}
	else
	{
		ans += c;
		edge.emplace_back(u, p);
	}
	for (int v = 1; v <= N; ++v)
	{
		if (visit[v]) continue;
		dfs(v, u);
	}
}