#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, arr[100'010];
int dn[] = { -1,0,1 }, ans = INT_MAX;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			int a1 = arr[0] + dn[i], a2 = arr[1] + dn[j];
			int dif = a2 - a1;
			int cnt = abs(i-1)+abs(j-1);
			for (int i = 2; i < N; ++i)
			{
				int tmp = arr[i] - a2;
				if (tmp == dif) 
				{
					a2 = arr[i]; continue;
				}
				if (tmp + 1 == dif)
				{
					a2 = arr[i] + 1; ++cnt; continue;
				}
				else if (tmp - 1 == dif)
				{
					a2 = arr[i] - 1; ++cnt; continue;
				}
				else
				{
					goto next;
				}
			}
			ans = min(cnt, ans);
		next:;
		}
	}
	cout << (ans==INT_MAX?-1:ans);
}