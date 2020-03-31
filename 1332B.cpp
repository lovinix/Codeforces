#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int T, N, A[1010], ans[1010];
vector<int> B[12];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		for (int i = 0; i < N; ++i)
		{
			cin >> A[i];
		}
		memset(ans, 0, sizeof ans);
		for (auto& vt : B) vt.clear();
		int cur = 1;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 1; j <= 11; ++j)
			{
				for (auto& v : B[j])
				{
					if (gcd(v, A[i]) == 1) goto next;
				}
				ans[i] = j;
				B[j].emplace_back(A[i]);
				break;
			next:;
			}
		}
		cout << *max_element(ans,ans+N) << "\n";
		for (int i = 0; i < N; ++i)
			cout << ans[i] << " ";
		cout << "\n";
	}
}