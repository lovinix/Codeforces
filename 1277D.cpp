#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, cnt[4];
string arr[200'010];
vector<int> lst[4], anslst;
set<string> st;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int ans = 0;
		memset(cnt, 0, sizeof cnt);
		for (int i = 0; i < 4; ++i)
			lst[i].clear();
		anslst.clear();
		st.clear();
		for (int i = 0; i < N; ++i)
		{
			string s;
			cin >> s;
			arr[i + 1] = s;
			st.emplace(s);
			if (s[0] == '0' && s.back() == '0') cnt[0]++, lst[0].emplace_back(i+1);
			else if (s[0] == '1' && s.back() == '1') cnt[3]++, lst[3].emplace_back(i+1);
			else if (s[0] == '0' && s.back() == '1') cnt[1]++, lst[1].emplace_back(i+1);
			else cnt[2]++, lst[2].emplace_back(i+1);
		}
		if (cnt[0] && cnt[3] && cnt[1] == 0 && cnt[2] == 0)
		{
			cout << "-1\n"; continue;
		}
		int mx = cnt[1] > cnt[2] ? 1 : 2;
		int mn = cnt[1] > cnt[2] ? 2 : 1;
		int dif = (cnt[mx] - cnt[mn]) / 2;
		int cnt = 0;
		for (auto& i : lst[mx])
		{
			reverse(arr[i].begin(), arr[i].end());
			if (st.count(arr[i])) continue;
			++cnt;
			anslst.emplace_back(i);
			if (cnt == dif) break;
		}
		if (cnt < dif) { cout << "-1\n"; }
		else
		{
			cout << dif << "\n";
			for (int i = 0; i < dif; ++i)
				cout << anslst[i] << " ";
			cout << '\n';
		}

	}
}