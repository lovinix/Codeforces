#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, K;
priority_queue<int, vector<int>, greater<int>> A;
priority_queue<int> B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		while (!A.empty()) A.pop();
		while (!B.empty()) B.pop();
		cin >> N >> K;
		for (int i = 0; i < N; ++i)
		{
			int x; cin >> x;
			A.emplace(x);
		}
		for (int i = 0; i < N; ++i)
		{
			int x; cin >> x;
			B.emplace(x);
		}
		while (K-- && A.top() < B.top())
		{
			int x = A.top(), y = B.top();
			A.pop(); B.pop();
			A.emplace(y); B.emplace(x);
		}
		int ans = 0;
		while (!A.empty())
		{
			int x = A.top();
			ans += x;
			A.pop();
		}
		cout << ans << "\n";
	}
}