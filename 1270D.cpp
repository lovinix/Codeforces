#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, K, l, h;
pii mn, mx;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	cout << "? ";
	for (int i = 1; i <= K; ++i)
	{
		cout << i << " ";
	}
	cout << endl;
	cin >> mn.second >> mn.first;
	cout << "? ";
	for (int i = 1; i <= K + 1; ++i)
	{
		if (i == mn.second) continue;
		cout << i << " ";
	}
	cout << endl;
	cin >> mx.second >> mx.first;
	if (mx < mn) swap(mx, mn);
	for (int i = 1; i <= K + 1; ++i)
	{
		if (i == mn.second || i == mx.second) continue;
		cout << "? ";
		for (int j = 1; j <= K + 1; ++j)
		{
			if (j == i) continue;
			cout << j << " ";
		}
		cout << endl;
		int a, b;
		cin >> a >> b;
		(a == mx.second ? l : h)++;
	}
	cout << "! " << l + 1;
}