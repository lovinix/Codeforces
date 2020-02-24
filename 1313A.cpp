#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, A[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A[0] >> A[1] >> A[2];
		sort(A, A + 3);
		reverse(A, A + 3);
		int ans = 0;
		if (A[0]) { ++ans; --A[0]; }
		if (A[1]) { ++ans; --A[1]; }
		if (A[2]) { ++ans; --A[2]; };
		if (A[0] && A[1]) { ++ans; --A[0]; --A[1]; }
		if (A[0] && A[2]) { ++ans; --A[0]; --A[2]; }
		if (A[1] && A[2]) { ++ans; --A[1]; --A[2]; }
		if (A[0] && A[1] && A[2]) ++ans;
		cout << ans << '\n';
	}
}