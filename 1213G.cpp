#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using tu = tuple<int, int, int>;
using pll = pair<lli, lli>;

int N, M, p[200'010];
tu arr[200'010];
vector<pll> vt, psum;

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v, int w)
{
	u = f(u); v = f(v);
	if (u == v) return;
	vt.emplace_back(w, 1LL * p[u] * p[v]);
	p[u] += p[v];
	p[v] = u;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	memset(p, -1, sizeof p);
	for (int i = 0; i < N-1; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		arr[i] = { w,u,v };
	}
	sort(arr, arr + N-1);
	for (int i = 0; i < N-1; ++i)
	{
		auto& [w, u, v] = arr[i];
		m(u, v, w);
	}
	psum.emplace_back(0, 0);
	for (int i = 0; i < vt.size(); ++i)
	{
		psum.emplace_back(vt[i].first, vt[i].second + psum[i].second);
	}
	while (M--)
	{
		int q; cin >> q;
		int idx = upper_bound(psum.begin(), psum.end(), pll(q, LLONG_MAX)) - psum.begin() - 1;
		cout << psum[idx].second << " ";
	}
}
