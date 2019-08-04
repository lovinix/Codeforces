#include <bits/stdc++.h>
using namespace std;

int n, arr[200002], cnt[200001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
		cnt[arr[i]]++;
	}
	int mx = -1, val = -1;
	for (int i = 0; i <= 200000; ++i)
	{
		if (cnt[i] > mx) { mx = cnt[i]; val = i; }
	}
	int idx = 0;
	for(int i=1;i<=n;++i)
		if (arr[i] == val) { idx = i; break; }
	cout << n - mx << "\n";
	for (int i = idx - 1; i > 0; --i)
	{
		if (arr[i] > val) { cout << "2 " << i << " " << i + 1 << "\n"; }
		else if (arr[i] < val) { cout << "1 " << i << " " << i + 1 << "\n"; }
	}
	for (int i = idx + 1; i <= n; ++i)
	{
		if (arr[i] > val) { cout << "2 " << i << " " << i - 1 << "\n"; }
		else if (arr[i] < val) { cout << "1 " << i << " " << i - 1 << "\n"; }
	}
}