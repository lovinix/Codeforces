#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1001][1001], ind[1001];
vector<int> leaf;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i < N; ++i)
	{
		int u, v, x;
		cin >> u >> v >> x;
		arr[u][v] = x;
		arr[v][u] = x;
		ind[u]++; ind[v]++;
	}
	for (int i = 1; i < N; ++i)
	{
		if (ind[i] == 1)
			leaf.push_back(i);
	}

}