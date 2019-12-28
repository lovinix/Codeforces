#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli arr[14], ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 0; i < 14; ++i)
		cin >> arr[i];
	for (int i = 0; i < 14; ++i)
	{
		if (arr[i] == 0) continue;
		lli tmp[14] = { 0, };
		for (int j = 0; j < 14; ++j) tmp[j] = arr[j];
		lli v = tmp[i];
		tmp[i] = 0;
		for (int j = 0; j < 14; ++j) tmp[j] += v / 14;
		v %= 14;
		for (int j = (i+1)%14; v; v--, j = (j + 1) % 14)
			tmp[j]++;
		lli a = 0;
		for (auto& v : tmp)
			if (v % 2 == 0) a += v;
		ans = max(ans, a);
	}
	cout << ans;
}