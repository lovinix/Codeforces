#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, A[5010], MX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	iota(A, A + N + 1, 0);
	for (int i = N - 2; i > 0; i -= 2) MX += i;
	for (int i = 1; i <= N && M; ++i)
	{
		if (MX - M >= N - 2 * i) { MX -= N - 2 * i; }
		else A[i] = 1e9 - N + i;
	}
	if (MX != M) cout << -1;
	else
	{
		for (int i = 1; i <= N; ++i)
			cout << A[i] << " ";
	}
}