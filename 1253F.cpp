#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define int long long
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

int N, M, K, Q, prnt[100'010], w[100'010], p[100'010], d[100'010], num[100'010], hld[100'010], node_num;
int cl[100'010], dist[100'010], seg[4 * 100'010];
vector<pii> adj[100'010], adj2[100'010];
auto cmp = [](tu& t1, tu& t2) {return get<2>(t1) > get<2>(t2); };
priority_queue<tu, vector<tu>, decltype(cmp)> pq(cmp), pq2(cmp);

int f(int u);
int m(int u, int v, int wt);
void dfs(int u);
void dfs2(int u);
void su(int i, int v, int n = 1, int s = 1, int e = K);
int sq(int l, int r, int n = 1, int s = 1, int e = K);
int q(int u, int v);


signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K >> Q;
	for (int i = 0; i < M; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		adj2[u].emplace_back(v, w);
		adj2[v].emplace_back(u, w);
	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= K; ++i)
	{
		pq.emplace(i, i, 0);
		dist[i] = 0;
		cl[i] = i;
	}
	while (!pq.empty())
	{
		auto [s, u, d] = pq.top();
		pq.pop();
		if (d != dist[u]) continue;
		for (auto& [v, w] : adj2[u])
		{
			if (dist[v] > dist[u] + w)
			{
				dist[v] = dist[u] + w;
				cl[v] = cl[u];
				pq.emplace(s, v, dist[v]);
			}
			else pq2.emplace(cl[u], cl[v], dist[v] + dist[u] + w);
		}
	}
	memset(p, -1, sizeof p);
	while (!pq2.empty())
	{
		auto [u, v, d] = pq2.top();
		pq2.pop();
		if (m(u, v, d)) { adj[u].emplace_back(v, d); adj[v].emplace_back(u, d); }
	}
	memset(p, 0, sizeof p);
	dfs(1);
	hld[1] = 1;
	dfs2(1);
	for (int i = 1; i <= K; ++i)
	{
		for (auto& [j, wt] : adj[i])
			su(max(num[i], num[j]), wt);
	}
	while (Q--)
	{
		int a, b;
		cin >> a >> b;
		cout << q(a, b) << "\n";
	}
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

int m(int u, int v, int wt)
{
	u = f(u), v = f(v);
	if (u == v) return 0;
	p[u] = min({ p[u],p[v],-wt });
	p[v] = u;
	return 1;
}

void dfs(int u)
{
	w[u] = 1;
	for (auto& [v,wt] : adj[u])
	{
		if (w[v] == 0)
		{
			p[v] = u;
			d[v] = d[u] + 1;
			dfs(v);
			w[u] += w[v];
		}
	}
}

void dfs2(int u)
{
	int cc = -1;
	num[u] = ++node_num;
	for (auto& [v,wt] : adj[u])
	{
		if (p[v] == u && (cc == -1 || w[v] > w[cc]))
			cc = v;
	}
	if (cc != -1) { hld[cc] = hld[u]; dfs2(cc); }
	for (auto& [v,wt] : adj[u])
	{
		if (p[v] == u && v != cc)
		{
			hld[v] = v;
			dfs2(v);
		}
	}
}

void su(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	seg[n] = max(seg[n], v);
	if (s == e) return;
	int m = s + e >> 1;
	if (i <= m) su(i, v, n * 2, s, m);
	else su(i, v, n * 2 + 1, m + 1, e);
}

int sq(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return max(sq(l, r, n * 2, s, m), sq(l, r, n * 2 + 1, m + 1, e));
}

int q(int u, int v)
{
	int ret = 0;
	while (hld[u] != hld[v])
	{
		if (d[hld[u]] < d[hld[v]]) swap(u, v);
		ret = max(ret, sq(num[hld[u]], num[u]));
		u = p[hld[u]];
	}
	if (d[u] > d[v]) swap(u, v);
	return max(ret,sq(num[u] + 1, num[v]));
}