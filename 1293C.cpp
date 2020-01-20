#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, Q, A[2][100'010], cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> Q;
	while (Q--)
	{
		int r, c;
		cin >> r >> c;
		r--;
		A[r][c] ^= 1;
		int st = A[r ^ 1][c - 1] + A[r ^ 1][c] + A[r ^ 1][c + 1];
		if (A[r][c]) cnt += st;
		else cnt -= st;
		cout << (cnt == 0 ? "YES\n" : "NO\n");
		pow(1, 1);
	}
}