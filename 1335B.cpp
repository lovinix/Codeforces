#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A, B;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N >> A >> B;
		string ans;
		for (int i = 0, cnt = 0; i < A; ++i)
		{
			if (cnt < B) ans += 'a' + cnt++;
			else ans += ans.back();
		}
		for (int i = A; i < N; ++i)
			ans += ans[i - A];
		cout << ans << "\n";
	}
}