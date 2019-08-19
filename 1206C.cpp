#include <bits/stdc++.h>
using namespace std;

int n, a[2 * 100'001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	if (!(n & 1)) { cout << "NO"; return 0; }
	for(int i=1,j=1;i<=n;++i,j+=2)
		a[i] = j + (i & 1 ? 0 : 1), a[i + n] = j + (i & 1 ? 1 : 0);
	cout << "YES\n";
	for (int i = 1; i <= 2 * n; ++i)
		cout << a[i] << " ";
}
