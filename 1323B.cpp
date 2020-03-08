#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, A[40'010], B[40'010];
lli K;
vector<int> a, b;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	for (int i = 1; i <= M; ++i)
		cin >> B[i];
	for (int i = 1, cnt = 0; i <= N; ++i)
	{
		cnt += A[i];
		if (A[i] && !A[i + 1]) { a.emplace_back(cnt); cnt = 0; }
	}
	for (int i = 1, cnt = 0; i <= M; ++i)
	{
		cnt += B[i];
		if (B[i] && !B[i + 1]) { b.emplace_back(cnt); cnt = 0; }
	}
	lli ans = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (K % i) continue;
		lli j = K / i;
		if (j > M) continue;
		lli ca = 0, cb = 0;
		for (auto& v : a)
			if (v >= i) ca += v - i + 1;
		for (auto& v : b)
			if (v >= j) cb += v - j + 1;
		ans += ca * cb;
	}
	cout << ans;
}