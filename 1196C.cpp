#include <bits/stdc++.h>
using namespace std;

int Q, n;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> n;
		int l = -1e5, r = 1e5, u = 1e5, d = -1e5;
		bool f = 1;
		for (int i = 0; i < n; ++i)
		{
			int x,y, f1, f2, f3, f4;
			cin >> x >> y >> f1 >> f2 >> f3 >> f4;
			if (!f1)
			{
				if (r < x) goto end;
				if (l < x)  l = x; 
			}
			if (!f2)
			{
				if (d > y) goto end;
				if (u > y) u = y;
			}
			if (!f3)
			{
				if (l > x) goto end;
				if (r > x) r = x;
			}
			if (!f4)
			{
				if (u < y) goto end;
				if (d < y) d = y;
			}
			continue;
		end:
			cout << "0\n";
			f = 0;
			while(++i < n)
				cin >> x >> y >> f1 >> f2 >> f3 >> f4;
		}
		if (f) cout << "1 " << l << " " << d << "\n";
	}
}