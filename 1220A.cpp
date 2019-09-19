#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, cnt[10000];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	string s; cin >> s;
	for (auto& c : s) cnt[c]++;
	int m = min({ cnt['o'], cnt['n'], cnt['e'] });
	cnt['o'] -= m; cnt['e'] -= m;
	while (m--) cout << "1 ";
	m = min({ cnt['z'], cnt['e'], cnt['r'], cnt['o'] });
	while (m--) cout << "0 ";
}