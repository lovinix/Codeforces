#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using lli = long long;
using pll = pair<lli, lli>;

int N;
pll A[100'010];

int ccw(pll& p1, pll& p2, pll& p3)
{
	lli t = p1.X * p2.Y + p2.X * p3.Y + p3.X * p1.Y - p2.X * p1.Y - p3.X * p2.Y - p1.X * p3.Y;
	return t < 0 ? -1 : t>0;
}

bool cmp(pll& p1, pll& p2)
{
	int t = ccw(A[0], p1, p2);
	return t ? t > 0:(p1.X + p1.Y < p2.X + p2.Y);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	if (N & 1) { cout << "NO"; return 0; }
	for (int i = 0; i < N; ++i)
		cin >> A[i].first >> A[i].second;
	swap(A[0], *min_element(A, A + N));
	sort(A + 1, A + N, cmp);
	for (int i = 0; i < N / 2; ++i)
	{
		lli X1 = A[i + 1].X - A[i].X;
		lli Y1 = A[i + 1].Y - A[i].Y;
		lli X2 = A[i + N / 2].X - A[(i + 1 + N / 2)%N].X;
		lli Y2 = A[i + N / 2].Y - A[(i + 1 + N / 2)%N].Y;
		if (X1 == X2 && Y1 == Y2) continue;
		else { cout << "NO"; return 0; }
	}
	cout << "YES";
}