#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K, A[110];
set<int> s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> K;
		s.clear();
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
			s.emplace(A[i]);
		}
		if (s.size() > K) { cout << "-1\n"; continue; }
		for (int i = 1; s.size() < K; ++i)
			s.emplace(i);
		cout << (s.size() * N) << "\n";
		for (int i = 0; i < N; ++i)
		{
			for (auto& v : s)
				cout << v << " ";
		}
		cout << "\n";
	}
}