#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, M;
lli ansd;
set<int> vst;
queue<pii> q;
vector<int> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int x; cin >> x;
		q.emplace(x, 0);
		vst.emplace(x);
	}
	while (M)
	{
		auto [y, d] = q.front();
		q.pop();
		for (auto i : { -1, 1 })
		{
			int ny = y + i;
			if (vst.count(ny)) continue;
			vst.emplace(ny);
			q.emplace(ny, d + 1);
			ans.emplace_back(ny);
			ansd += d + 1;
			if (!--M) goto end;
		}
	}
end:;
	cout << ansd << "\n";
	for (auto& i : ans)
		cout << i << " ";

}