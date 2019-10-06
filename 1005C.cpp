#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, ans;
lli arr[120'010];
map<lli, int> m;
set<lli> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		s.emplace(arr[i]);
		if (m.count(arr[i]))
			m[arr[i]]++;
		else m[arr[i]] = 1;
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 32; j >= 0; --j)
		{
			lli t = 1LL << j;
			lli a = t - arr[i];
			if (s.count(a))
			{
				if (a == arr[i] && m[arr[i]] == 1) continue;
				else goto next;
			}
		}
		++ans;
	next:;
	}
	cout << ans;
}