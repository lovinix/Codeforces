#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[110];

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
		sort(A, A + N);
		reverse(A, A + N);
		for (int i = 0; i < N; ++i)
			cout << A[i] << " ";
		cout << "\n";
	}
}