#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

lli Q, N, K;
vector<lli> z;
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while (Q--)
	{
		cin >> N >> K >> s;
		z.clear();
		for (int i = 0; i < s.length(); ++i)
		{
			if (s[i] == '0') z.emplace_back(i);
		}
		for (int i = 0; i < z.size() && K; ++i)
		{
			if (z[i] == i) continue;
			lli cnt = min(z[i] - i, K);
			swap(s[z[i]], s[z[i] - cnt]);
			K -= cnt;
		}
		cout << s << "\n";
	}
}