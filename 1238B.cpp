#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli Q, N, R, sum;
vector<lli> arr;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N >> R;
		arr.clear();
		for (int i = 1; i <= N; ++i)
		{
			lli u; cin >> u;
			arr.emplace_back(u);
		}
		sort(arr.begin(), arr.end());
		arr.erase(unique(arr.begin(), arr.end()), arr.end());
		sum = 0;
		int cnt = 0;
		for (int i = arr.size()-1; i >= 0; --i,++cnt)
		{
			arr[i] -= sum;
			if (arr[i] <= 0) { cout << cnt << "\n"; goto next; }
			sum += R;
		}
		cout << cnt << "\n";
	next:;
	}
}