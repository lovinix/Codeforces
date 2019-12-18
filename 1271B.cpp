#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string s, t;
vector<int> anss, anst;


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	t = s;
	for (int i = 0; i < s.length() - 1; ++i)
	{
		if (s[i] == 'W') { s[i] = 'B'; s[i + 1] = (s[i + 1] == 'B' ? 'W' : 'B'); anss.emplace_back(i + 1); }
	}
	if (s.back() == 'B')
	{
		cout << anss.size() << '\n';
		for (auto& i : anss)
			cout << i << " ";
		return 0;
	}
	for (int i = 0; i < t.length() - 1; ++i)
	{
		if (t[i] == 'B') { t[i] = 'W'; t[i + 1] = (t[i + 1] == 'W' ? 'B' : 'W'); anst.emplace_back(i + 1); }
	}
	if (t.back() == 'W')
	{
		cout << anst.size() << '\n';
		for (auto& i : anst)
			cout << i << " ";
		return 0;
	}
	cout << -1;

}