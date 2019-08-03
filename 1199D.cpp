#include <bits/stdc++.h>
using namespace std;
using pa = pair<int, int>;
using tu = tuple<int, int, int>;

bool f[200'001];
int n,m, arr[200'001];
pa idx[200'001];
tu q[200'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> arr[i];
	cin >> m;
	for (int i = 0; i < m; ++i)
	{
		int a, b, c;
		cin >> a >> b;
		if (a == 1)
		{
			cin >> c;
			q[i] = { a,b,c };
			idx[b] = { b,i };
			f[b] = 1;
		}
		else
		{
			q[i] = { a,b,0 };
		}
	}
	sort(idx, idx + n+1, [](pa& p1, pa& p2){return p1.second > p2.second; });
	int mx = -1;
	for (int i = m - 1, j=0; i >= 0; --i)
	{
		int a, b, c;
		tie(a, b, c) = q[i];
		if (a == 2)
		{
			mx = max(mx, b);
		}
		else
		{
			while (j<=200'000 && idx[j].second == i)
			{
				arr[idx[j++].first] = max(c, mx);
			}
		}
	}
	for (int i = 1; i <= n; ++i)
	{
		cout << (f[i]?arr[i]:max(arr[i],mx)) << " ";
	}
}