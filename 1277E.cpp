#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, M, A, B, cnt[2], p[200'010];
vector<int> ds[200'010];
set<pii> st;

int f(int u);
void m(int u, int v);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M >> A >> B;
		for (int i = 1; i <= N; ++i)
		{
			p[i] = -1;
			ds[i].clear();
			ds[i].emplace_back(i);
		}
		st.clear();
		cnt[0] = cnt[1] = 0;
		for (int i = 0; i < M; ++i)
		{
			int u, v;
			cin >> u >> v;
			st.emplace(min(u,v),max(u,v));
			if (u != A && u != B && v != A && v != B)
				m(u, v);
		}
		for (int i = 1; i <= N; ++i)
		{
			if (i == A || i == B) continue;
			if (p[i] >= 0) continue;
			int flag = 0;
			for (auto& u : ds[i])
			{
				if (st.count({ min(u,A),max(u,A) }))
				{
					flag |= 1;
				}
				if (st.count({ min(u,B),max(u,B) }))
				{
					flag |= 2;
				}
			}
			if (flag == 1) cnt[0] += ds[i].size();
			if (flag == 2) cnt[1] += ds[i].size();
		}
		cout << 1LL * cnt[0] * cnt[1] << "\n";
	}
}

int f(int u)
{
	return p[u] < 0 ? u : p[u] = f(p[u]);
}

void m(int u, int v)
{
	u = f(u), v = f(v);
	if (u == v) return;
	if (ds[u].size() < ds[v].size()) swap(u, v);
	for (auto& i : ds[v])
		ds[u].emplace_back(i);
	p[u] += p[v];
	p[v] = u;
}