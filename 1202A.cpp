#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while(T--)
	{
		string s, t;
		cin >> s >> t;
		int idx = 0;
		for (int i = t.length() - 1; i >= 0; --i)
			if (t[i] == '1') break;
			else ++idx;
		int ans = 0;
		for(int i=s.length()-idx-1;i>=0;--i)
		{
			if (s[i] == '1')
			{
				cout << ans<<"\n";
				goto end;
			}
			else
				++ans;
		}
	end:;
	}
}
