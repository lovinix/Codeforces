#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;

int N, M, arr[60][60], b[60][60];
vector<pii> ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 1; i <= N; ++i)
		for (int j = 1; j <= M; ++j)
			cin >> arr[i][j];

	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			if (arr[i][j] == 1 && arr[i+1][j] == 1 && arr[i][j+1] == 1 && arr[i+1][j+1] == 1)
			{
				ans.emplace_back(i, j);
				for (int k = i; k < i + 2; ++k)
					for (int l = j; l < j + 2; ++l)
						b[k][l] = 1;
			}
		}
	}
	for(int i=1;i<=N;++i)
		for(int j=1;j<=M;++j)
			if (arr[i][j] != b[i][j]) { cout << -1; return 0; }
	cout << ans.size() << "\n";
	for (auto& [i, j] : ans)
		cout << i << " " << j << "\n";
}