#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e9;
int N, A[110], dp[110][110][110][2];

int recv(int idx, int o, int e, int r)
{
	if (o<0 || e<0 || o>idx || e>idx) return MAX;
	if (dp[idx][o][e][r] != -1) return dp[idx][o][e][r];
	if (idx == 0) return 0;
	dp[idx][o][e][r] = MAX;
	int f = A[idx] ? A[idx] % 2 : r;
	if (f != r) return MAX;
	dp[idx][o][e][r] = min({ dp[idx][o][e][r], recv(idx - 1,o - f,e - !f ,r), recv(idx - 1,o - f,e - !f,r ^ 1) + 1 });
	return dp[idx][o][e][r];
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	memset(dp, -1, sizeof dp);
	cin >> N;
	for (int i = 1; i <= N; ++i)
		cin >> A[i];
	if (A[N] == 0)
		cout << min(recv(N, N / 2 + N % 2, N / 2, 0), recv(N, N / 2 + N % 2, N / 2, 1));
	else
		cout << recv(N, N / 2 + N % 2, N / 2, A[N] % 2);
}