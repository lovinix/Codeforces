#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long h, l;
	cin >> h >> l;
	cout <<fixed<<setprecision(7) << (double)(l * l - h * h) / 2 / h;
}