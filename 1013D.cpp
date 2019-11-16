#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using pii = pair<int, int>;

int N, M, Q, R[200'010], C[200'010], rcnt, ccnt;
pii arr[200'010];
lli ans;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> M >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int r, c;
		cin >> r >> c;
		arr[i] = { r,c };
	}
	sort(arr, arr + Q);
	for (int i = 0; i < Q; ++i)
	{
		auto& [r, c] = arr[i];
		if (c < r)
		{
			if (R[1] == 0) { R[1] = 1; C[1] = 1; }
			else if (C[c] == 0) C[c] = 1;
			else if (R[r] == 0) R[r] = 1;
		}
		else
		{
			if (R[1] == 0) { R[1] = 1; C[1] = 1; }
			else if (R[r] == 0) R[r] = 1;
			else if (C[c] == 0) C[c] = 1;
		}
	}
	for (int i = 2; i <= M; ++i)
	{
		if (C[i] == 0) ++ccnt;
	}
	for (int i = 1; i <= N; ++i)
	{
		if (R[i] == 0) ++ans;
		ans += ccnt;
		ccnt = 0;
	}
	cout << ans;
}