#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int>;
using lli = long long;

int N, K, cnt[200'010];
lli seg[4 * 200'010], lazy[4 * 200'010];
tu arr[200'010];
vector<int> ans;

void p(int n, int l, int r);
void u(int l, int r, int n = 1, int s = 1, int e = 200'000);
lli q(int l, int r, int n = 1, int s = 1, int e = 200'000);


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int l, r; cin >> l >> r;
		arr[i] = { l,r,i + 1 };
	}
	sort(arr, arr + N, [](tu& t1, tu& t2)
		{
			auto& [l1, r1, i1] = t1;
			auto& [l2, r2, i2] = t2;
			return r1 == r2 ? l1 > l2 : r1 < r2;
		});
	for (int i = 0; i < N; ++i)
	{
		auto [l, r, idx] = arr[i];
		if (q(l, r) >= K) { ans.emplace_back(idx); goto next; }
		u(l, r);
	next:;
	}
	cout << ans.size() << "\n";
	for (auto& i : ans)
		cout << i << " ";
}

void p(int n, int l, int r)
{
	if (!lazy[n]) return;
	seg[n] += lazy[n];
	if (l == r) { lazy[n] = 0; return; }
	lazy[n * 2] += lazy[n];
	lazy[n * 2 + 1] += lazy[n];
	lazy[n] = 0;
}

void u(int l, int r, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return;
	if (l <= s && e <= r) { lazy[n] += 1; p(n, s, e); return; }
	int m = s + e >> 1;
	u(l, r, n * 2, s, m);
	u(l, r, n * 2 + 1, m + 1, e);
	seg[n] = max(seg[n * 2], seg[n * 2 + 1]);
}

lli q(int l, int r, int n, int s, int e)
{
	p(n, s, e);
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return max(q(l, r, n * 2, s, m), q(l, r, n * 2 + 1, m + 1, e));
}