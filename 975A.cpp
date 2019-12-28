#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		string t;
		cin >> t;
		int f = 0;
		for (auto& c : t)
			f |= 1 << c - 'a';
		s.emplace(f);
	}
	cout << s.size();
}