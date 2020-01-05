#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, Q;
string s[21], t[21];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
		cin >> s[i];
	for (int i = 0; i < M; ++i)
		cin >> t[i];
	cin >> Q;
	while (Q--)
	{
		int y;
		cin >> y;
		cout << s[(y - 1) % N] + t[(y - 1) % M] << '\n';
	}
}