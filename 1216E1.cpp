#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int Q, K;
vector<lli> v;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	lli sum = 0, cnt = 1, cur = 10;
	v.emplace_back(0);
	for (; sum <= 1e9; ++cnt)
	{
		if (cnt == cur) { ++cnt, cur *= 10; }
		sum += cnt;
		v.emplace_back(sum);
	}
	cin >> Q;
	while (Q--)
	{
		cin >> K;
		int idx = lower_bound(v.begin(), v.end(), K) - v.begin();
		if (v[idx] != K) idx--;
		while (idx > 9)
		{
			K = idx;
			idx = lower_bound(v.begin(), v.end(), idx) - v.begin();
			if (v[idx] != K) idx--;
		}
		cout << K - v[idx] << "\n";
	}
}