#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using tu = tuple<int, int, int, int>;

int N, M, ans[110];
tu arr[110];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int s, d, c;
		cin >> s >> d >> c;
		arr[i] = { s,d,c,i+1 };
		ans[d] = M + 1;
	}
	sort(arr, arr + M,
		[](tu& t1, tu& t2)
		{
			return get<1>(t1) < get<1>(t2);
		});
	int cur = 1, bef = 1;
	for (int i = 0; i < M; ++i)
	{
		auto& [s, d, c, idx] = arr[i];
		if (s <= cur) 
		{
			for (; c; ++cur)
			{
				if (ans[cur]) { continue; }
				ans[cur] = idx;
				--c;
			}
		}
		else
		{
			int mn = INT_MAX, id = -1;
			for (int j = i + 1; j < M; ++j)
			{
				auto& [s2, d2, c2, idx2] = arr[j];
				if (c2 <= 0) continue;
				if (s2 <= cur) 
				{ 
					for (; cur < s && c2; ++cur)
					{
						if (ans[cur]) continue;
						c2--; ans[cur] = idx2;
					}
					goto next;
				}
				else 
				{
					if (mn > s2) { mn = s2; id = j; }
				}
			}
			if (cur != s)
			{
				auto& [s2, d2, c2, idx2] = (id!=-1?arr[id]:arr[i]);
				for (; cur < min(s, s2); ++cur)
				{
					if (ans[cur]) continue;
					ans[cur] = 0;
				}
			}
		next:;
			--i;
		}
		if (cur > d) { cout << -1; return 0; }
	}
	for (int i = 1; i <= N; ++i)
		cout << ans[i] << " ";

}