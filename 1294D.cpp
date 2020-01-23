#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, X, R[400'010];
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i <= 400'010; ++i) s.emplace(i);
	cin >> Q >> X;
	while (Q--)
	{
		int y; cin >> y;
		y %= X;
		s.erase(R[y] * X + y);
		R[y]++;
		cout << *s.begin() << "\n";
	}
}