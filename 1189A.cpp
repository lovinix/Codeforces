#include <bits/stdc++.h>
using namespace std;

int num[2];

int main()
{
	int n;
	char s[110];
	cin >> n >> s;
	for (int i = 0; i < n; ++i)
		num[s[i] - '0']++;
	if (num[0] != num[1])
	{
		cout << "1\n" << s;
	}
	else
	{
		cout << "2\n" << s[0]<<" ";
		for (int i = 1; i < n; ++i)
			cout << s[i];
	}
}