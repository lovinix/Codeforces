#include <bits/stdc++.h>

using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int n, s, t;
		cin >> n>>s>>t;
		int tmp = (s + t) - n;
		cout << max(s - tmp, t - tmp) + 1 << "\n";
	}
}