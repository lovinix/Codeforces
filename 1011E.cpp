#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K, arr[100'010], v[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		arr[i] %= K;
	}
	int g = arr[0];
	for (int i = 1; i < N; ++i)
		g = gcd(g, arr[i]);
	int t = g;
	while (!v[t])
	{
		v[t] = 1;
		t = (t + g) % K;
	}
	int cnt = 0;
	for (int i = 0; i < K; ++i)
		if (v[i]) ++cnt;
	cout << cnt << "\n";
	for (int i = 0; i < K; ++i)
		if (v[i]) cout << i << " ";
}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(a % b, b) : b;
}