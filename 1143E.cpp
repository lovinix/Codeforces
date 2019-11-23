#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, Q, pm[200'010], seq[200'010], next[200'010];
vector<int> loc[200'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 1; i <= N; ++i)
	{
		cin >> pm[i];
	}
	for (int i = 1; i <= M; ++i)
	{
		cin >> seq[i];
	}
	for (int i = 1; i <= N; ++i)
	{
		loc[pm[i]].emplace_back(i);
		next[pm[i]] = pm[i + 1];
	}
	next[pm[N]] = pm[1];


}