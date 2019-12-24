#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int a, b;
	cout << "b" << endl;
	cin >> b;
	if (b == 0 || b == -1) return 0;
	b = min(b, 299);
	for (int i = 0; i <= b; ++i)
		ans += 'a';
	cout << ans << endl;
	cin >> a;
	if (a == 0 || a == -1) return 0;
	if (a == 1) { ans.pop_back(); cout << ans << endl; return 0; }
	N = b + 1;
	int cur = a;
	for (int i = 0; i < N; ++i)
	{
		ans[i] = 'b';
		cout << ans << endl;
		int t;
		cin >> t;
		if (t == 0 || t == -1) return 0;
		if (t > cur) { ans[i] = 'a'; }
		else cur = t;
	}
	cout << ans;
	
}