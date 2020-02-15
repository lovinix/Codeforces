#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M;
string ans;
vector<string> vt;
set<string> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		string str;
		cin >> str;
		reverse(str.begin(), str.end());
		if (s.count(str)) { s.erase(str); vt.emplace_back(str); }
		else
		{
			reverse(str.begin(), str.end());
			s.emplace(str);
		}
	}
	for (auto& str : vt)
	{
		ans += str;
		reverse(str.begin(), str.end());
	}
	for (auto& str : s)
	{
		for (int i = 0, j = str.length() - 1; i < j; ++i, --j)
		{
			if (str[i] != str[j]) goto next;
		}
		ans += str;
		break;
	next:;
	}
	for (auto it = vt.rbegin(); it != vt.rend(); ++it)
		ans += *it;
	cout << ans.length() << "\n" << ans;
}