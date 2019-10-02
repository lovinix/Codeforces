#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K;
set<int> inq;
deque<int> deq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
	{
		int t; cin >> t;
		if (inq.count(t)) continue;
		if (deq.size() < K) deq.emplace_front(t), inq.emplace(t);
		else
		{
			int e = deq.back();
			deq.pop_back();
			inq.erase(e);
			deq.emplace_front(t);
			inq.emplace(t);
		}
	}
	cout << deq.size() << "\n";
	for (auto& i : deq)
		cout << i << " ";
}