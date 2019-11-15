#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M;
long double A[1010], B[1010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
		if (A[i] == 1) { cout << -1; return 0; }
	}
	for (int i = 0; i < N; ++i)
	{
		cin >> B[i];
		if (B[i] == 1) { cout << -1; return 0; }
	}
	long double x = M;
	x = B[0] * x / (B[0] - 1);
	x = A[N-1] * x / (A[N-1] - 1);
	for (int i = N - 1; i > 0; --i)
	{
		x = B[i] * x / (B[i] - 1);
		x = A[i - 1] * x / (A[i - 1] - 1);
	}
	cout << fixed << setprecision(8) << x - M;
}