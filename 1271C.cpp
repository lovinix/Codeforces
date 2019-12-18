#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, X, Y, tmp1[3], tmp2[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> X >> Y;
	auto cntX = &tmp1[1], cntY = &tmp2[1];
	for (int i = 0; i < N; ++i)
	{
		int x, y;
		cin >> x >> y;
		int f = 0;
		if (x != X) cntX[x - X > 0 ? 1 : -1]++;
		if (y != Y) cntY[y - Y > 0 ? 1 : -1]++;
	}
	int mxX = 0, mxY = 0, cnt = 0;
	for (int i = -1; i <= 1; ++i)
	{
		for (int j = -1; j <= 1; ++j)
		{
			if ( (i==0 || j==0) && cnt <= cntX[i] + cntY[j])
			{
				cnt = cntX[i] + cntY[j];
				mxX = i; mxY = j;
			}
		}
	}
	cout << cnt << "\n" << X + mxX << " " << Y + mxY;
}