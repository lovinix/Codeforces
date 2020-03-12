#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int T, N;
pii A[5010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			auto& [a, b] = A[i];
			cin >> a;
			b = i;
		}
		sort(A, A + N);
		for (int i = 0; i + 2 < N; ++i)
		{
			auto& [x1, i1] = A[i];
			auto& [x2, i2] = A[i + 1];
			auto& [x3, i3] = A[i + 2];
			if (x1 == x2 && i2 > i1 + 1) { cout << "YES\n"; goto next; }
			if (x2 == x3 && i3 > i2 + 1) { cout << "YES\n"; goto next; }
			if (x1 == x3) { cout << "YES\n"; goto next; }
		}
		cout << "NO\n";
	next:;
	}
}