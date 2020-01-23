#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli T, A[3], N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A[0] >> A[1] >> A[2] >> N;
		sort(A, A + 3);
		lli cnt = A[2] - A[1] + A[2] - A[0];
		if (cnt > N || (N - cnt) % 3) cout << "NO\n";
		else cout << "YES\n";
	}
}