#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N, M, dn[] = { 0,1,0,-1 }, dm[] = { 1,0,-1,0 };
lli K, cnt = 1;
vector<int> row[100'010], col[100'010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < K; ++i)
	{
		int r, c; 
		cin >> r >> c;
		row[r].emplace_back(c);
		col[c].emplace_back(r);
	}
	for (int i = 1; i <= N; ++i)
		sort(row[i].begin(), row[i].end());
	for (int i = 1; i <= M; ++i)
		sort(col[i].begin(), col[i].end());
	int r = 1, c = 1, d = 0;
	while (1)
	{
		int next;
		decltype(row[r].begin()) pos;
		switch (d)
		{
		case 0:
			pos = upper_bound(row[r].begin(), row[r].end(), c);
			if (pos == row[r].end()) next = M + 1;
			else next = *pos;
			if (next - c == 1) goto end;
			else { cnt += next - c - 1; d++; }
			c = next - 1;
			break;
		case 1:
			pos = upper_bound(col[c].begin(), col[c].end(), r);
			if (pos == col[c].end()) next = N + 1;
			else next = *pos;
			if (next - r == 1) goto end;
			else { cnt += next - r - 1; ++d; }
			r = next - 1;
			break;
		case 2:
			pos = lower_bound(row[r].begin(), row[r].end(), c);
			if (row[r].size() == 0 || pos==row[r].begin()) next = 0;
			else next = *(pos-1);
			if (c - next == 1) goto end;
			else { cnt += c - next - 1; ++d; }
			c = next + 1;
			break;
		case 3:
			pos = lower_bound(col[c].begin(), col[c].end(), r);
			if (col[c].size() == 0 || pos == col[c].begin()) next = 0;
			else next = *(pos-1);
			if (r - next == 1) goto end;
			else { cnt += r - next - 1; ++d; }
			r = next + 1;
			break;
		}
		if (d == 4) d = 0;
	}
end:
	if (cnt + K == 1LL* N * M) cout << "Yes";
	else cout << "No";
}