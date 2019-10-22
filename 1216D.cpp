#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, arr[200'010], mx;

int gcd(int a, int b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		mx = max(mx, arr[i]);
	}
	lli y = 0, z = 1;
	for (int i = 0; i < N; ++i)
	{
		arr[i] = mx - arr[i];
		if (arr[i] != 0) z = arr[i];
	}
	for (int i = 0; i < N; ++i)
	{
		if (arr[i] != 0) z = gcd(z, arr[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		y += arr[i] / z;
	}
	cout << y << " " << z;

}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}