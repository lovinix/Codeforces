#include <bits/stdc++.h>
using namespace std;
using lli = long long;

struct Seg
{
	int l, r, v;
	Seg() : l(0), r(0), v(0) {}
};

lli n, I, k, po=1;
vector<int> arr;
vector<Seg> tree(2);

void u(int i, lli s=0, lli e=1e9, int node=1);
int q(lli l, lli r, lli s=0, lli e=1e9, int node=1);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n >> I;
	k = 8*I / n;
	for (int i = 0; i < n; ++i)
	{
		int t;
		cin >> t;
		arr.emplace_back(t);
		u(t);
	}
	lli tmp = 2;
	sort(arr.begin(), arr.end());
	arr.erase(unique(arr.begin(), arr.end()), arr.end());
	while (k)
	{
		if (k & 1) po *= tmp;
		k >>= 1;
		tmp *= 2;
		if (po > arr.size())
		{
			cout << "0";
			return 0;
		}
	}
	lli cnt = -1;
	for (int i = 0; i+po-1 < arr.size(); ++i)
	{
		lli cur = q(arr[i], arr[i+po-1]);
		cnt = max(cnt, cur);
	}
	cout << n-cnt;
}

void u(int i, lli s, lli e, int node)
{
	if (s > i && e < i) return;
	++tree[node].v;
	if (s == e) return;
	lli m = (s + e) / 2;
	if (i <= m)
	{
		if (!tree[node].l)
		{
			tree[node].l = tree.size();
			tree.emplace_back(Seg());
		}
		u(i, s, m, tree[node].l);
	}
	else
	{
		if (!tree[node].r)
		{
			tree[node].r = tree.size();
			tree.emplace_back(Seg());
		}
		u(i, m + 1, e, tree[node].r);
	}
}

int q(lli l, lli r, lli s, lli e, int node)
{
	if (s > r || e < l) return 0;
	if (l <= s && e <= r) return tree[node].v;
	lli m = (s + e) / 2;
	int ret = 0;
	if (tree[node].l)
		ret += q(l, r, s, m, tree[node].l);
	if (tree[node].r)
		ret += q(l, r, m + 1, e, tree[node].r);
	return ret;
}