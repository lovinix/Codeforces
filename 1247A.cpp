#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	if (N == 9 && M == 1) { cout << "9 10"; return 0; }
	if (M > N + 1 || N > M) { cout << -1; return 0; }
	if (M == N) cout << M * 10 << " " << N * 10 + 1;
	else cout << N << " " << M;
}