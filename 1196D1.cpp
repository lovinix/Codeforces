#include <bits/stdc++.h>
using namespace std;

string s[3] = { "RGB","GBR","BRG" };

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		int n, k;
		cin >> n >> k;
		string in;
		cin >> in;
		int mn = k;
		for (int z = 0; z < 3; ++z)
		{
			int i = 0, j = 0, cnt = 0;
			for (; i < k; ++i)
			{
				if (in[i] != s[z][i % 3]) cnt++;
			}
			mn = min(mn, cnt);
			for (; i < in.length();++i,++j)
			{
				if (in[i] != s[z][i % 3]) cnt++;
				if (in[j] != s[z][j % 3]) cnt--;
				mn = min(mn, cnt);
			}
		}
		cout << mn << "\n";
	}
}