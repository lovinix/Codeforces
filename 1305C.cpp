#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, A[200'010], cnt[1010], ans = 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		int v; cin >> v;
		cnt[v % M]++;
		A[i] = v;
	}
	for (int i = 0; i < M; ++i)
	{
		if (cnt[i] > 1) { cout << "0"; return 0; }
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = i + 1; j < N; ++j)
		{
			ans = (ans * abs(A[i] - A[j])) % M;
		}
	}
	cout << ans;

}