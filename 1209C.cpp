#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 200'000;
int seg[4 * (MAX + 1)], T, N;
string s;
auto t = 1 << 1;
void u(int i, int v, int n = 1, int s = 0, int e = N);
int q(int l, int r, int n = 1, int s = 0, int e = N);


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> T;
	while (T--)
	{
		cin >> N;
		cin >> s;
		for (int i = 0; i < s.length(); ++i)
			u(i, s[i]);
		u(N, MAX);
		string ans;
		int first = -1, last = -1;
		for (int i = 0; i < s.length(); ++i)
		{
			int v = q(i + 1, N);
			if (v >= s[i] && (first==-1 || first>=s[i])) ans += '1';
			else
			{
				if (last > s[i]) { cout << "-\n"; goto next; }
				else { ans += '2'; last = s[i]; if (first == -1) first = s[i]; }
			}
		}
		cout << ans << "\n";
	next:;
	}
}

void u(int i, int v, int n, int s, int e)
{
	if (s > i || e < i) return;
	if (s == e) { seg[n] = v; return; }
	int m = s + e >> 1;
	if (i <= m) u(i, v, n * 2, s, m);
	else u(i, v, n * 2 + 1, m + 1, e);
	seg[n] = min(seg[n * 2], seg[n * 2 + 1]);
}

int q(int l, int r, int n, int s, int e)
{
	if (s > r || e < l) return MAX;
	if (l <= s && e <= r) return seg[n];
	int m = s + e >> 1;
	return min(q(l, r, n * 2, s, m), q(l, r, n * 2 + 1, m + 1, e));
}

