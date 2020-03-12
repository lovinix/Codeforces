#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, A[200'010];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> s;
		for (int i = 0; i <= s.length(); ++i)
			A[i] = 0;
		for (int i = 1; i <= s.length(); ++i)
		{
			if (s[i - 1] == 'R') A[i] = 0;
			else A[i] = A[i - 1] + 1;
		}
		cout << *max_element(A, A + s.length() + 1) + 1 << "\n";
	}
}