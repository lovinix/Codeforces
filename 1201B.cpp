#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int n, arr[100'001];
lli sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
		sum += arr[i];
	}
	if (sum & 1) { cout << "NO"; return 0; }
	sort(arr, arr + n);
	sum -= arr[n - 1];
	if (sum < arr[n - 1]) cout << "NO";
	else cout << "YES";
}