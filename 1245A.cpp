#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, A, B;

int gcd(int a, int b);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> A >> B;
		cout << (gcd(A, B) == 1 ? "Finite\n" : "Infinite\n");
	}
}

int gcd(int a, int b)
{
	if (a < b) swap(a, b);
	return a % b ? gcd(b, a % b) : b;
}