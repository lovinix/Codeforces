#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int t, N;
priority_queue<int> pq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--)
	{
		cin >> N;
		int ans = 0;
		while (N--)
		{
			int k;
			cin >> k;
			while (!pq.empty() && pq.top() > k)
				pq.pop(), ++ans;
			pq.push(k);
		}
		cout << ans << "\n";
		while (!pq.empty()) pq.pop();
	}
}