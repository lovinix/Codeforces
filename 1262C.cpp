#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N, K;
string s;
vector<pii> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K >> s;
		ans.clear();
		int cnt = (K - 1) * 2;
		for (int i = 0; i < cnt; ++i)
		{
			if ((i & 1) && s[i] == ')') continue;
			if ((i & 1) == 0 && s[i] == '(') continue;
			for (int j = i; j < s.length(); ++j)
			{
				if ((i & 1) && s[j] == ')') { reverse(&s[i], &s[j+1]); ans.emplace_back(i, j); break; }
				if ((i & 1) == 0 && s[j] == '(') { reverse(&s[i], &s[j+1]); ans.emplace_back(i, j); break; }
			}
		}
		for (int i = cnt; i < s.length(); ++i)
		{
			if (s[i] == '(') continue;
			for (int j = i + 1; j < s.length(); ++j)
			{
				if (s[j] == '(') { reverse(&s[i], &s[j + 1]); ans.emplace_back(i, j); break; }
			}
		}
		cout << ans.size() << '\n';
		for (auto& [l, r] : ans)
			cout << l + 1 << " " << r + 1 << "\n";
	}
}