#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N;
int arr[1'000'010];
vector<int> vt;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
			cin >> arr[i];
		vt.clear();
		sort(arr, arr + N);
		for (int i = 0; i + 1 < N; ++i)
		{
			if (arr[i] == arr[i + 1]) vt.emplace_back(arr[i++]);
		}
		double dif = INT_MAX;
		int ansl, ansr;
		for (int i = 0; i + 1 < vt.size(); ++i)
		{
			if (dif > (vt[i] * 1.0 / vt[i + 1] + vt[i + 1] * 1.0 / vt[i]))
			{
				ansl = vt[i]; ansr = vt[i + 1];
				dif = vt[i] * 1.0 / vt[i + 1] + vt[i + 1] * 1.0 / vt[i];
			}
		}
		cout << ansl << " " << ansl << " " << ansr << " " << ansr << "\n";
	}
}