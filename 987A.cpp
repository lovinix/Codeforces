#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

map<string, string> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	m["purple"] = "Power";
	m["green"] = "Time";
	m["blue"] = "Space";
	m["orange"] = "Soul";
	m["red"] = "Reality";
	m["yellow"] = "Mind";
	int N;
	cin >> N;
	while (N--)
	{
		string s;
		cin >> s;
		m[s] = " ";
	}
	int ans = 0;
	for (auto& it : m)
	{
		if (it.second != " ")
			++ans;
	}
	cout << ans << "\n";
	for (auto& it : m)
	{
		if (it.second != " ")
			cout << it.second << "\n";
	}

}