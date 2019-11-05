#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int Q, N, arr[110], v[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		memset(v, 0, sizeof v);
		for (int i = 1; i <= N; ++i)
		{
			for (int j = 1; j < N; ++j)
			{
				if (arr[j] == i)
				{
					while (j > 0 && arr[j-1]>arr[j] && !v[j - 1]) 
					{ 
						swap(arr[j], arr[j - 1]);
						v[j - 1] = 1;
						j--;
					}
					break;
				}
			}
		}
		for (int i = 0; i < N; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}
}