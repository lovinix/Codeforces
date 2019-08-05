#include <bits/stdc++.h>
using namespace std;

int a, b, sum;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> a;
	while(1)
	{
		int b = a, sum = 0;
		while(b)
		{
			sum += b % 10;
			b /= 10;
		}
		if (!(sum % 4)) { cout << a; return 0; }
		++a;
	}
}