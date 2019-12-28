#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[200'010];
set<int> s;
deque<int> dq;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 1; i <= N; ++i) s.emplace(i);
	for (int i = 1; i <= N; ++i)
	{
		cin >> arr[i];
		if (arr[i] != 0) s.erase(arr[i]);
	}
	for (auto& i : s) dq.emplace_back(i);
	for (int i = 1; i <= N; ++i)
	{
		if (arr[i]) continue;
		if (s.count(i))
		{
			if (dq.front() == i) { dq.emplace_back(dq.front()); dq.pop_front(); }
			arr[i] = dq.front();
			s.erase(i);
			dq.pop_front();
		}
	}
	for (int i = 1; i <= N; ++i)
	{
		if (arr[i]) continue;
		if (dq.front() == i) { dq.emplace_back(dq.front()); dq.pop_front(); }
		arr[i] = dq.front();
		dq.pop_front();
	}
	for (int i = 1; i <= N; ++i)
		cout << arr[i] << " ";
}