#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define X first
#define Y second
using namespace std;
using pii = pair<int, int>;

pii sq[7];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 6; ++i)
		cin >> sq[i].X >> sq[i].Y;
	if (sq[3] > sq[5]) { swap(sq[3], sq[5]); swap(sq[4], sq[6]); }
	if(sq[3].X<=sq[1].X && sq[3].Y<=sq[1].Y && sq[4].X >=sq[2].X && sq[4].Y>=sq[2].Y)
	{
		cout << "NO"; return 0;
	}
	if (sq[5].X <= sq[1].X && sq[5].Y <= sq[1].Y && sq[6].X >= sq[2].X && sq[6].Y >= sq[2].Y)
	{
		cout << "NO"; return 0;
	}
	if(sq[3].Y >sq[5].Y) { swap(sq[3], sq[5]); swap(sq[4], sq[6]); }
	if (sq[3].Y<=sq[1].Y && sq[6].Y>=sq[2].Y && sq[4].Y >= sq[5].Y && sq[3].X <= sq[1].X && sq[4].X >= sq[2].X && sq[5].X <= sq[1].X && sq[6].X >= sq[2].X)
	{
		cout << "NO"; return 0;
	}
	if (sq[3].X > sq[5].X) { swap(sq[3], sq[5]); swap(sq[4], sq[6]); }
	if (sq[3].X<=sq[1].X && sq[6].X>=sq[2].X && sq[4].X >= sq[5].X && sq[3].Y <= sq[1].Y && sq[4].Y >= sq[2].Y && sq[5].Y <= sq[1].Y && sq[6].Y >= sq[2].Y)
	{
		cout << "NO"; return 0;
	}
	cout << "YES";
}