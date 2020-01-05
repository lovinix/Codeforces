#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, K;
lli ans;
string arr[1510];
set<string> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		s.emplace(arr[i]);
	}
	for (int i = 0; i < N; ++i)
	{
		s.erase(arr[i]);
		for (int j = i + 1; j < N; ++j)
		{
			s.erase(arr[j]);
			string tmp;
			for (int k = 0; k < K; ++k)
			{
				if (arr[i][k] == arr[j][k]) tmp += arr[i][k];
				else tmp += 'S' ^ 'E' ^ 'T' ^ arr[i][k] ^ arr[j][k];
			}
			ans += s.count(tmp);
		}
		for (int j = i + 1; j < N; ++j)
			s.emplace(arr[j]);
	}
	cout << ans;
}