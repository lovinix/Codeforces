#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, arr[100'001], zr, pr = 1;
lli cnt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		if (arr[i] == 0) ++zr, ++cnt;
		else if (arr[i] > 0) cnt += arr[i] - 1;
		else cnt += -1*arr[i] - 1, pr*=-1;
	}
	if (pr == 1) cout << cnt;
	else
	{
		if (zr > 0) cout << cnt;
		else cout << cnt + 2;
	}
	
}
