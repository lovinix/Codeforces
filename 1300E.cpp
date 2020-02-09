#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using ld = long double;

int N;
lli A[1'000'010];
ld ans[1'000'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
		cin >> A[i];
	for (int i = 0; i < N; ++i)
	{
		int j = i + 1;
		lli s = A[i];
		while (j < N && (ld)s / (j - i) > (ld)(s + A[j]) / (j - i + 1)) { s += A[j]; j++; }
		for (int k = i; k < j; ++k)
		{
			ans[k] = (ld)s / (j - i);
		}
		i = j - 1;
	}
	for (int i = 0; i < N; ++i)
		cout << setprecision(9) << fixed << ans[i] << "\n";
}