#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int K, N;
string s, t;
vector<pii> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> K;
	while (K--)
	{
		cin >> N >> s >> t;
		ans.clear();
		for (int i = 0; i < N; ++i)
		{
			if (s[i] != t[i])
			{
				for (int j = i + 1; j < N; ++j)
				{
					if (s[j] == t[j]) continue;
					if (t[i] == s[j])
					{
						ans.emplace_back(j + 1, j + 1);
						ans.emplace_back(i + 1, j + 1);
						swap(s[j], t[j]);
						swap(s[i], t[j]);
						break;
					}
					else if (s[i] == t[j])
					{
						ans.emplace_back(j + 1, j + 1);
						ans.emplace_back(j + 1, i + 1);
						swap(s[j], t[j]);
						swap(s[j], t[i]);
						break;
					}
					else if (s[i] == s[j])
					{
						ans.emplace_back(j + 1, i + 1);
						swap(s[j], t[i]);
						break;
					}
					else if (t[i] == t[j])
					{
						ans.emplace_back(i + 1, j + 1);
						swap(s[i], t[j]);
						break;
					}
				}
			}
		}
		if (s == t)
		{
			cout << "Yes\n" << ans.size() << "\n";
			for (auto& [i, j] : ans)
				cout << i << " " << j << "\n";
		}
		else
			cout << "No\n";
	}
}