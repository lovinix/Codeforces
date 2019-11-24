#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using tu = tuple<int, int, int>;

int N, M, arr[200'010], seg[4 * 200'010], ans[200'010];
tu qu[200'010];

auto cmp = [](pii& p1, pii& p2) {return p1.second == p2.second ? p1.first > p2.first:p1.second < p2.second; };
priority_queue<pii, vector<pii>, decltype(cmp)> pq(cmp);

void u(int i, int n = 1, int s = 1, int e = 200'000);
int q(int k, int n=1, int s=1, int e=200'000);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		pq.emplace(i, arr[i]);
	}
	cin >> M;
	for (int i = 1; i <= M; ++i)
	{
		int k, p;
		cin >> k >> p;
		qu[i] = { k,p,i };
	}
	sort(qu + 1, qu + M + 1);
	for (int curi = 1, curq=1; curq <= M; ++curq)
	{
		auto [k, p, idx] = qu[curq];
		while (k >= curi)
		{
			auto [i, v] = pq.top();
			pq.pop();
			++curi;
			u(i);
		}
		ans[idx] = arr[q(p)];
	}
	for (int i = 1; i <= M; ++i)
		cout << ans[i] << "\n";
}

void u(int i, int n, int s, int e)
{
	seg[n]++;
	if (s == e) return;
	int m = s + e >> 1;
	if(i<=m)
		u(i, n * 2, s, m);
	else
		u(i, n * 2 + 1, m + 1, e);
}

int q(int k, int n, int s, int e)
{
	if (s == e) return s;
	int m = s + e >> 1;
	if (seg[n * 2] >= k) return q(k, n * 2, s, m);
	else return q(k - seg[n * 2], n * 2 +1, m+1, e);
}