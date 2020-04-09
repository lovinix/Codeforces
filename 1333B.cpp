#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[100'010], B[100'010], tmp[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> A[i];
		for (int i = 0; i < N; ++i)
			cin >> B[i];
		memset(tmp, 0, sizeof tmp);
		auto C = &tmp[1];
		for (int i = 0; i < N; ++i)
		{
			if (A[i] > B[i] && C[-1] == 0) { cout << "NO\n"; goto next; }
			if (A[i] < B[i] && C[1] == 0) { cout << "NO\n"; goto next; }
			C[A[i]]++;
		}
		cout << "YES\n";
	next:;
	}
}