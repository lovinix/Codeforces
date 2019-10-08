#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using lli = long long;

const int MOD = 998244353;
int N;
pii arr[300'010];
lli fac[300'010], ans;

lli recv(int x);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	ans = recv(N);
	for (int i = 0; i < N; ++i)
		cin >> arr[i].first >> arr[i].second;
	sort(arr, arr + N);
	int s = 1;
	int f = arr[0].first, cnt = 1;
	lli m = 1;
	for (int i = 1; i < N; ++i)
	{
		if (arr[i].first == f) ++cnt;
		else 
		{ 
			if (cnt > 1) m=(m*recv(cnt))%MOD;
			cnt = 1; f = arr[i].first;
		}
		if (arr[i].second < arr[i - 1].second) s = 0;
	}
	if (cnt > 1) m=(m*recv(cnt))%MOD;
	ans = (ans - m + MOD) % MOD;
	m = 1;
	sort(arr, arr + N, [](pii& p1, pii& p2) {return p1.second < p2.second; });
	f = arr[0].second, cnt = 1;
	for (int i = 1; i < N; ++i)
	{
		if (arr[i].second == f) ++cnt;
		else
		{
			if (cnt > 1) m = (m * recv(cnt)) % MOD;
			cnt = 1; f = arr[i].second;
		}
	}
	if (cnt > 1) m = (m * recv(cnt)) % MOD;
	ans = (ans - m + MOD) % MOD;
	sort(arr, arr + N);
	pii fi = arr[0];
	cnt = 1;
	m = 1;
	for (int i = 1; i < N; ++i)
	{
		if (fi == arr[i]) cnt++;
		else
		{
			if (cnt > 1) m = (m * recv(cnt)) % MOD;
			cnt = 1; fi = arr[i];
		}
	}
	if (cnt > 1) m = (m * recv(cnt)) % MOD;
	if(s)
		ans = (ans + m) % MOD;
	cout << ans;
}

lli recv(int x)
{
	if (fac[x]) return fac[x];
	if (x == 1) return 1;
	return fac[x] = (x * recv(x - 1))%MOD;
}