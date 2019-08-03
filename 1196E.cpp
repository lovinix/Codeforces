#include <bits/stdc++.h>
using namespace std;

int q;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> q;
	while (q--)
	{
		int b, w;
		cin >> b >> w;
		if (b >= w * 3 + 2 || w >= b * 3 + 2) { cout << "NO\n"; continue; }
		cout << "YES\n";
		if (w > b)
		{
			int cnt = 0;
			for (int i = 0; i < 2*b; i += 2)
			{
				cout << 2 << " " << 3 + i << "\n";
				cout << 2 << " " << 3 + i + 1 << "\n";
				++cnt;
			}
			for (int i = 0; i < 2*b && cnt < w; i += 2, ++cnt)
				cout << 1 << " " << 3 + i << "\n";
			for (int i = 0; i < 2*b && cnt < w; i += 2, ++cnt)
				cout << 3 << " " << 3 + i << "\n";
			if (cnt < w) { cout << "2 2\n"; ++cnt; }
		}
		else
		{
			int cnt = 0;
			for (int i = 0; i < 2*w; i += 2)
			{
				cout << 3 << " " << 3 + i << "\n";
				cout << 3 << " " << 3 + i + 1 << "\n";
				++cnt;
			}
			for (int i = 0; i < 2*w && cnt < b; i += 2, ++cnt)
				cout << 2 << " " << 3 + i << "\n";
			for (int i = 0; i < 2*w && cnt < b; i += 2, ++cnt)
				cout << 4 << " " << 3 + i << "\n";
			if (cnt < b) { cout << "3 2\n"; ++cnt; }
		}
	}
}