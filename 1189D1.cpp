#include <bits/stdc++.h>
using namespace std;

int ind[100010];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int N;
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v;
		cin >> u >> v;
		ind[u]++; ind[v]++;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (ind[i] == 2)
		{
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
}