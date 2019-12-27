#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, arr[3];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		for (int i = 0; i < 3; ++i)
			cin >> arr[i];
		sort(arr, arr + 3);
		if (arr[0] + arr[1] + 1 >= arr[2])
			cout << "Yes\n";
		else cout << "No\n";
	}
}