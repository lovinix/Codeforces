#include <bits/stdc++.h>
using namespace std;

string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> s;
	char cur = CHAR_MAX;
	for (auto& c : s)
	{
		cout << (c <= cur ? "Mike\n" : "Ann\n");
		cur = min(c, cur);
	}
}