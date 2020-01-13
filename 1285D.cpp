#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> vt;

int recv(vector<int>& v, int b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int t; cin >> t;
		vt.emplace_back(t);
	}
	cout << recv(vt, 30);
}

int recv(vector<int>& v, int b)
{
	if (v.size() == 0 || b < 0) return 0;
	vector<int> l, r;
	for (auto& i : v)
		(i >> b & 1 ? r : l).emplace_back(i);
	if (l.empty()) return recv(r, b - 1);
	if (r.empty()) return recv(l, b - 1);
	return min(recv(l, b - 1), recv(r, b - 1)) + (1 << b);
}