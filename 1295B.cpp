#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, X, B[100'010];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> X >> s;
		for (int i = 1; i <= N; ++i)
		{
			B[i] = B[i - 1] + (s[i - 1] == '0' ? 1 : -1);
		}
		int ans = 0;
		for (int i = 0; i < N; ++i)
		{
			if (B[i] == X && B[N] == 0)
			{
				cout << "-1\n"; goto next;
			}
			if (int dif = X - B[i]; (dif>=0&& B[N]>0 || dif<=0 && B[N]<0) && dif % B[N] == 0) ++ans;
		}
		cout << ans << "\n";
	next:;
	}
}