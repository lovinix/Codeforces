#include <bits/stdc++.h>
using namespace std;

int N;
bool arr[10];
string s;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> s;
	for(int i=0;i<s.length();++i)
	{
		if(s[i]=='L')
		{
			for(int j=0;j<10;++j)
			{
				if(!arr[j])
				{
					arr[j] = 1; break;
				}
			}
		}
		else if(s[i]=='R')
		{
			for(int j=9;j>=0;--j)
			{
				if(!arr[j])
				{
					arr[j] = 1; break;
				}
			}
		}
		else
		{
			arr[s[i] - '0'] = 0;
		}
	}
	for (int i = 0; i < 10; ++i)
		cout << arr[i];
}
