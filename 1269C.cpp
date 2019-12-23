#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, K;
string s, t;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N >> K >> s;
	cout << N << "\n";
	t = s;
	for (int i = 0; i < K; ++i)
	{
		for (int j = i + K; j < s.length(); j += K)
			s[j] = s[i];
	}
	for (int i = 0; i < s.length(); ++i)
	{
		if (s[i] < t[i]) goto cont;
		if (s[i] > t[i]) { cout << s; return 0; }
	}
	cout << s;
	return 0;
	cont:
	for (int i = K - 1; i >= 0; --i)
	{
		if (s[i] != '9')
		{
			s[i]++;
			for (int j = i + K; j < s.length(); j += K)
				s[j] = s[i];
			cout << s;
			return 0;
		}
		s[i] = '0';
		for (int j = i + K; j < s.length(); j += K)
			s[j] = '0';
	}
	cout << s;
}