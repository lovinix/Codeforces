#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		s.clear();
		while (N--)
		{
			int v; cin >> v;
			s.emplace(v);
		}
		cout << s.size() << "\n";
	}
}