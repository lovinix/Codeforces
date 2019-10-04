#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int A, B, X, cnt[2];
char cur;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> A >> B >> X;
	cnt[0] = A; cnt[1] = B;
	cur = A < B ? 0 : 1;
	for (int i = 0; i < A + B; ++i)
	{
		if (X > 1)
		{
			s += (cur^=1) + '0';
			cnt[cur]--;
			if (i > 0) X--;
		}
		else
		{
			while (cnt[cur]--) s += (cur) + '0';
			while (cnt[cur^1]--) s += (cur^1) + '0';
			break;
		}
	}
	cout << s;
}