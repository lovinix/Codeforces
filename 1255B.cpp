#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, M, w[1010], vst[1010], tot, cnt, minu, minv, minw = INT_MAX;
vector<pii> ans;

void dfs(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		memset(vst, 0, sizeof vst);
		minu = 0, minv = 0, minw = INT_MAX;
		tot = cnt = 0;
		ans.clear();
		for (int i = 0; i < N; ++i)
			cin >> w[i];
		if (N == 2) { cout << "-1\n"; continue; }
		dfs(0);
		while (cnt < M) { ans.emplace_back(minu, minv); ++cnt; tot += minw; }
		if (cnt > M) { cout << "-1\n"; continue; }
		cout << tot << "\n";
		for (auto& [u, v] : ans)
			cout << u + 1 << " " << v + 1 << "\n";
	}
}

void dfs(int u)
{
	vst[u] = 1;
	int v=-1, c = INT_MAX;
	for (int i = 0; i < N; ++i)
	{
		if (i == u || vst[i]) continue;
		if (c >= w[i]+w[u]) { v = i; c = w[i]+w[u]; }
	}
	if (v != -1)
	{
		ans.emplace_back(u, v);
		tot += c;
		if (c <= minw) { minw = c; minu = u; minv = v; }
		cnt++;
		dfs(v);
	}
	else
	{
		ans.emplace_back(u, 0);
		tot += w[u] + w[0];
		++cnt;
	}
}