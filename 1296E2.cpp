#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, A[200'010];
string s;
set<int> cnt[200];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> s;
	for (char a = 'a'; a <= 'z'; ++a)
		for (int i = 1; i <= 1000; ++i)
			cnt[a].emplace(i);
	for (int i=0;i<N;++i)
	{
		int v = 1;
		for (int j = 1;; ++j)
		{
			for (char a = s[i] + 1; a <= 'z'; ++a)
			{
				if (!cnt[a].count(j)) goto next;
			}
			v = j;
			break;
		next:;
		}
		cnt[s[i]].erase(v);
		A[i] = v;
	}
	cout << *max_element(A,A+N) << '\n';
	for (int i = 0; i < N; ++i)
		cout << A[i] << " ";
}