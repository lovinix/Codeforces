#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using psi = pair<string, int>;

int T, N;
string s;
vector<psi> vt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> s;
		vt.clear();
		vt.emplace_back(s, 1);
		for (int k = 2, fl = !(N & 1); k <= N; ++k, fl ^= 1)
		{
			string tmp = s.substr(0, k - 1);
			if (fl) reverse(tmp.begin(), tmp.end());
			vt.emplace_back(s.substr(k - 1) + tmp, k);
		}
		sort(vt.begin(), vt.end());
		cout << vt[0].first << "\n" << vt[0].second << "\n";
	}
}