#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[110], cnt[110];
char ans[110];
set<int> s1,s2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> arr[i], cnt[arr[i]]++;
	for (int i = 1; i <= 100; ++i)
		if (cnt[i] == 0 || cnt[i] == 2)  continue;
		else if (cnt[i] == 1) s1.emplace(i);
		else s2.emplace(i);
	if ((s1.size()&1) && s2.size() == 0) { cout << "NO"; return 0; }
	int q = s1.size() / 2;
	int r = s1.size() % 2;
	for (int i = 0; i < N; ++i)
	{
		if (s1.count(arr[i]) && q) { ans[i] = 'A'; q--; }
		else if (s2.count(arr[i]) && r) { ans[i] = 'A'; r--; }
		else ans[i] = 'B';
	}
	cout << "YES\n";
	for (int i = 0; i < N; ++i)
		cout << ans[i];
}