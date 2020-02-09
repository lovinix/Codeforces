#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int z = 0, s = 0;
		for (int i = 0; i < N; ++i)
		{
			int a; cin >> a;
			z += a == 0;
			s += a;
		}
		int ans = z + (s + z == 0 ? 1 : 0);
		cout << ans << "\n";
	}
}