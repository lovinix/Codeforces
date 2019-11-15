#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, M, TF[31];

int main()
{
	cin >> M >> N;
	for (int i = 0; i < N; ++i)
	{
		cout << M << endl;
		fflush(stdout);
		int f;
		cin >> f;
		if (f == 0) { return 0; }
		if (f == 1) TF[i] = 0;
		if (f == -1) TF[i] = 1;
		if (f == -2) return 0;
	}
	int l = 1, r = M - 1, i = 0;
	while (l <= r)
	{
		int m = l + r >> 1;
		cout << m << endl;
		fflush(stdout);
		int f;
		cin >> f;
		if (f == -2) return 0;
		if (f == 0) return 0;
		if (f == 1 && TF[i] == 1 || f == -1 && TF[i] == 0)
			l = m + 1;
		else
			r = m - 1;
		i = (i + 1) % N;
	}
}