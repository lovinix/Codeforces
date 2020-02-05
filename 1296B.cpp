#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, X;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> X;
		int ms = 1e9, ans = 0;
		while (X)
		{
			int cur = X / ms;
			int l1 = to_string(X).length();
			ans += cur * ms;
			X -= cur * ms;
			X += cur * ms / 10;
			int l2 = to_string(X).length();
			if (cur==0 or l1 > l2)
				ms /= 10;
		}
		cout << ans << "\n";
	}
}