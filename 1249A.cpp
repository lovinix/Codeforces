#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N, arr[200], cnt[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> arr[i];
		}
		sort(arr, arr + N);
		if (N == 1) { cout << "1\n"; continue; }
		for (int i = 0; i < N - 1; ++i)
		{
			if (arr[i] + 1 == arr[i + 1])
			{
				cout << "2\n"; goto next;
			}
		}
		cout << "1\n";
	next:;
	}
}