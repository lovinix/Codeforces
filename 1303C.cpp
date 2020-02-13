#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		deque<char> dq;
		set<char> st;
		for (char c = 'a'; c <= 'z'; ++c)
			st.emplace(c);
		dq.emplace_back(s[0]);
		for (int i = 1; i < s.length(); ++i)
		{
			int p = find(dq.begin(), dq.end(), s[i - 1]) - dq.begin();
			int q = find(dq.begin(), dq.end(), s[i]) - dq.begin();
			if (p != dq.size() && q != dq.size())
			{
				if (abs(p - q) > 1)
				{
					cout << "NO\n";
					goto next;
				}
				else continue;
			}
			if (p != 0 && p != dq.size() - 1 && dq[p - 1] != s[i] && dq[p + 1] != s[i])
			{
				cout << "NO\n";
				goto next;
			}
			if (p == 0) dq.emplace_front(s[i]);
			else dq.emplace_back(s[i]);
		}
		cout << "YES\n";
		for (auto& c : dq)
		{
			cout << c;
			st.erase(c);
		}
		for (auto& c : st)
			cout << c;
		cout << "\n";
	next:;
	}
}