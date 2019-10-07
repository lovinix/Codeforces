#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli N, K;
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	if (K * (K - 1) < N) { cout << "NO"; return 0; }
	cout << "YES\n";
	int cnt = 0;
	for (int i = 1; i <= K - 1; ++i)
	{
		for (int j = i + 1; j <= K; ++j)
		{
			cout << i << " " << j << "\n";
			++cnt;
			if (cnt == N) goto end;
			cout << j << " " << i << "\n";
			++cnt;
			if (cnt == N) goto end;
		}
	}

end:;
}