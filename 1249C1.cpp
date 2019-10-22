#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli Q, N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		lli t = N;
		lli cur = 1;
		lli ans = 0;
		lli cnt = 0;
		while (t)
		{
			cur *= 3; t /= 3;
		}
		cur /= 3;
		t = N;
		while (t)
		{
			if (t / cur == 1) { ans += cur; t -= cur; }
			else if (t / cur == 2) 
			{
				ans += 3 * cur;
				cur *= 3;
				while ((ans % (3*cur))/cur == 2) 
				{ 
					ans += cur; cur *= 3; 
				}
				break; 
			}
			cur /= 3;
		}
		cout << ans << "\n";
	}
}