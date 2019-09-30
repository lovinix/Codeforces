#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int l, r;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> l >> r;
	for (; l <= r; ++l)
	{
		int cnt[10] = { 0, };
		int t = l;
		while (t)
		{
			cnt[t % 10]++;
			t /= 10;
		}
		for (int i=0;i<10;++i)
			if (cnt[i] > 1) goto loop;
		cout << l;
		return 0;
	loop:;
	}
	cout << -1;
}