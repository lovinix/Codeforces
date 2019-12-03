#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int l;
lli ans;
string s;
vector<lli> stk1, stk2;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> l;
	for (int i = 0; i < l; ++i)
	{
		cin >> s;
		if (s == "add" && stk1.size()) stk2.emplace_back(1);
		else if (s == "add" && stk1.empty()) ans++;
		else if (s == "for") { lli tmp; cin >> tmp; stk1.emplace_back(tmp); }
		else 
		{ 
			lli f = stk1.back(); stk1.pop_back();
			if (stk2.size()) { f *= stk2.back(); stk2.pop_back(); }
			else continue;
			if (stk1.size()) { stk2.emplace_back(f); }
			else ans += f;
		}
		if (ans >= INT_MAX) { cout << "OVERFLOW!!"; return 0; }
	}
	cout << ans;
}