#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		string ans;
		if (N >= 3 && N % 2) { ans += '7'; N -= 3; }
		for (; N; N -= 2) ans += '1';
		cout << ans << '\n';
	}
}