#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	vector<int> A = { 1,2,3,4 };
	for (int i = 0; i < A.size() - 2; ++i)
	{
		cout << ((A[i] + A[i + 1]) ^ (A[i + 1] + A[i + 2])) << " " << ((A[i + 1] + A[i + 1]) * (A[i] ^ A[i + 2])) << endl;
	}
}