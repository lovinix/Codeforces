#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, K, arr[100'010], prime[100'010];
lli ans;
vector<int> p;
vector<map<int, int>> vt;
map<map<int, int>, int> m;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	fill(prime, prime + 100'010, 1);
	prime[0] = prime[1] = 0;
	for (int i = 2; i * i <= 100'000; ++i)
	{
		if (!prime[i]) continue;
		for (int j = i + i; j <= 100'000; j += i)
			prime[j] = 0;
	}
	for (int i = 2; i <= 100'000; ++i)
		if (prime[i]) p.emplace_back(i);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	for (int i = 0; i < N; ++i)
	{
		map<int, int> tmp;
		for (auto& pr : p)
		{
			while (arr[i] % pr == 0) 
			{ 
				tmp[pr]++;
				arr[i] /= pr;
				if (tmp[pr] == K) tmp.erase(pr);
			}
			if (arr[i] == 1) break;
		}
		m[tmp]++;
		vt.emplace_back(tmp);
	}
	for (auto& cur : vt)
	{
		m[cur]--;
		map<int, int> tmp;
		for (auto& [k, v] : cur)
			tmp[k] += K - v;
		ans += m[tmp];
	}
	cout << ans;
}