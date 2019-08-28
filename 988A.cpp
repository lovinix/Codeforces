#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K;
vector<pii> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 1; i <= N; ++i)
	{
		int a; cin >> a;
		v.emplace_back(a, i);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end(), [](pii& p1, pii& p2) {return p1.first == p2.first; }), v.end());
	if (v.size() < K) { cout << "NO"; return 0; }
	cout << "YES\n";
	while (K--) cout << v[K].second << " ";
}