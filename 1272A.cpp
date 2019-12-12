#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, arr[] = { -1,0,1 }, ans = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		ans = INT_MAX;
		for (int i = 0; i < 3; ++i)
		{
			int A = a + arr[i];
			for (int j = 0; j < 3; ++j)
			{
				int B = b + arr[j];
				for (int k = 0; k < 3; ++k)
				{
					int C = c + arr[k];
					ans = min(ans, abs(A - B) + abs(B - C) + abs(A - C));
				}
			}
		}
		cout << ans << "\n";
	}
}