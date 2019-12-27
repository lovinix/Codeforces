#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long;

int T, N, M, A[100'010], B[100'010], cnt[100'010];
priority_queue<pii,vector<pii>,greater<pii>> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> M;
		memset(cnt, 0x3f, sizeof cnt);
		while (pq.size()) pq.pop();
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < M; ++i)
		{
			cin >> B[i];
			cnt[B[i]] = i;
		}
		lli ans = 0;
		for (int l = 0, r = 0; r < M; ++r)
		{
			if (pq.size() && pq.top().second == B[r]) { ans++; pq.pop(); continue; }
			while (B[r] != A[l]) { pq.emplace(cnt[A[l]], A[l]); ++l; }
			ans += pq.size() * 2 + 1;
			++l;
		}
		cout << ans << '\n';
	}
}