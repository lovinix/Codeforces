#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int N;
lli arr[100'010], K;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K;
	for (int i = 0; i < N; ++i)
		cin >> arr[i];
	sort(arr, arr + N);
	int l = 0, r = N - 1;
	lli lv = arr[0], rv = arr[N - 1];
	int lc = 0, rc = 0;
	while (1)
	{
		if (lv == rv) { cout << 0;  return 0;}
		int tl = upper_bound(arr, arr + N, arr[l]) - lower_bound(arr, arr + N, arr[l]);
		int tr = upper_bound(arr, arr + N, arr[r]) - lower_bound(arr, arr + N, arr[r]);
		if (lc < rc)
		{
			lli dif = (arr[l] - lv) * lc;
			if (dif > K) { lv += K / lc; goto end; }
			K -= dif;
			lv = arr[l];
			lc += tl;
			l += tl;
		}
		else
		{
			lli dif = (rv - arr[r]) * rc;
			if (dif > K) { rv -= K / rc; goto end; }
			K -= dif;
			rv = arr[r];
			rc += tr;
			r -= tr;
		}
	}
end:;
	cout << rv - lv;
}