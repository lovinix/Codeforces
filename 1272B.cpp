#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, cnt[300];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		string s;
		cin >> s;
		cnt['L'] = cnt['R'] = cnt['U'] = cnt['D'] = 0;
		for (auto& c : s)
			cnt[c]++;
		int ans = 0;
		int mn = min(cnt['L'], cnt['R']);
		ans += mn * 2;
		cnt['L'] = cnt['R'] = mn;
		mn = min(cnt['D'], cnt['U']);
		cnt['D'] = cnt['U'] = mn;
		ans += mn * 2;
		if (cnt['L'] == 0 || cnt['U'] == 0)
		{
			if (cnt['L'] == 0 && cnt['U'] == 0)
				cout << "0\n";
			else if (cnt['L'] != 0)
				cout << "2\nRL\n";
			else if (cnt['U'] != 0)
				cout << "2\nUD\n";
			else
				cout << "0\n"; continue;
		}
		cout << ans << '\n';
		for (int i = 0; i < cnt['R']; ++i)
			cout << 'R';
		for (int i = 0; i < cnt['U']; ++i)
			cout << 'U';
		for (int i = 0; i < cnt['L']; ++i)
			cout << 'L';
		for (int i = 0; i < cnt['D']; ++i)
			cout << 'D';
		cout << '\n';
	}
}