#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, Q;
lli arr[200'010], tmp[200'010], sum;
map<pii, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		tmp[i] = arr[i];
		sum += arr[i];
	}
	cin >> Q;
	while (Q--)
	{
		int s, t, u;
		cin >> s >> t >> u;
		if (m[{s, t}] > 0)
		{
			if(tmp[m[{s, t}]]++>=0) sum++;
			m[{s, t}] = u;
			if (u != 0 && tmp[u]-->0) sum--;
			cout << sum << '\n';
		}
		else
		{
			if (u == 0) { cout << sum << '\n'; continue; }
			m[{s, t}] = u;
			if (tmp[u]-->0) sum--;
			cout << sum << '\n';
		}
	}
}