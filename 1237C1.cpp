#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int, int>;

int N;
tu arr[2010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		int x, y, z;
		cin >> x >> y >> z;
		arr[i] = { x,y,z,i+1 };
	}
	for (int i = 0; i < N; i += 2)
	{		

		auto& [xa, ya, za, i1] = arr[i];
		auto& [xb, yb, zb, i2] = arr[i+1];
		for (int j = i + 2; j < N; ++j)
		{
			auto& [xc, yc, zc, i3] = arr[j];
			if (min(xa, xb) <= xc && xc <= max(xa, xb) && min(ya, yb) <= yc && yc <= max(ya, yb) && min(za, zb) <= zc && zc <= max(za, zb))
				swap(arr[i+1], arr[j]);
		}
		cout << i1 << " " << i2 << "\n";
	}
}