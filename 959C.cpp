#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	if (N < 6) { cout << "-1\n"; }
	else
	{
		cout << "1 2\n1 3\n1 4\n2 5\n2 6\n";
		for (int i = 7; i <= N; ++i)
			cout << "1 " << i << "\n";
	}
	for (int i = 2; i <= N; ++i)
	{
		cout << "1 " << i << "\n";
	}
}