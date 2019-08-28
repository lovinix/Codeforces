#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N;
string arr[101];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i) cin >> arr[i];
	sort(arr, arr + N, [](string& s1, string& s2) {return s1.length() == s2.length() ? s1 < s2 : s1.length() < s2.length(); });
	for (int i = 1; i < N; ++i)
	{
		if (arr[i].find(arr[i - 1]) == arr[i].npos)
		{
			cout << "NO"; return 0;
		}
	}
	cout << "YES\n";
	for (int i = 0; i < N; ++i)
		cout << arr[i] << "\n";
}