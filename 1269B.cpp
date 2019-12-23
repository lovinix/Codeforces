#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, A[2010], B[2010], ans = INT_MAX;
map<int, int> ma, mb;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		A[i] %= M;
		ma[A[i]]++;
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
		B[i] %= M;
		mb[B[i]]++;
	}
	for (int i = 0; i < N; ++i)
	{
		int dif = (B[i] - A[0] + M) % M;
		for (auto& [r, c] : ma)
		{
			if (mb[(r + dif) % M] != c) goto next;
		}
		ans = min(ans, dif);
	next:;
	}
	cout << ans;
}