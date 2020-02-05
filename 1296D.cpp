#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A, B, K;
map<int, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> A >> B >> K;
	int s = A + B;
	for (int i = 0; i < N; ++i)
	{
		int h; cin >> h;
		h %= s;
		if (h > 0 and h <= A) m[0]++;
		else { if (h == 0) h = s; h -= A; m[h / A + (h % A ? 1 : 0)]++; }
	}
	int ans = 0;
	for (auto& [k, v] : m)
	{
		if (k == 0) { ans += v; continue; }
		if (K <= 0 or K < k) break;
		int cnt = min(K, k * v);
		K -= cnt;
		ans += cnt / k;
	}
	cout << ans;
}