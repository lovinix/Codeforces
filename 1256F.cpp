#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using lli = long long;

int Q, N, cnt[2][26], idxarr[200'010], arrb[200'010], sorted[200'010];
lli ans;
string s, t;

void mergesort(int left, int right);
void merge(int left, int mid, int right);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> Q;
	while(Q--)
	{
		cin >> N >> s >> t;
		memset(cnt, 0, sizeof cnt);
		for (auto& c : s)
			cnt[0][c - 'a']++;
		for (auto& c : t)
			cnt[1][c - 'a']++;
		for (int i = 0; i < 26; ++i)
		{
			if (cnt[0][i] != cnt[1][i])
			{
				cout << "NO\n";
				goto next;
			}
		}
		for (int i = 0; i < 26; ++i)
		{
			if (cnt[0][i] > 1)
			{
				cout << "YES\n";
				goto next;
			}
		}
		for (int i = 0; i < N; ++i)
			idxarr[s[i] - 'a'] = i;
		for (int i = 0; i < N; ++i)
			arrb[i] = t[i] - 'a';
		ans = 0;
		mergesort(0, N - 1);
		if (ans & 1) { cout << "NO\n";}
		else { cout << "YES\n"; }
	next:;
	}
}

void mergesort(int left, int right)
{
	int mid = (left + right) / 2;
	if (left < right)
	{
		mergesort(left, mid);
		mergesort(mid + 1, right);
		merge(left, mid, right);
	}
}
void merge(int left, int mid, int right)
{
	int i, j, k;
	i = left;
	j = mid + 1;
	k = left;
	int acc = 0;
	while (i <= mid && j <= right)
	{
		if (idxarr[arrb[i]] < idxarr[arrb[j]])
		{
			sorted[k++] = arrb[i++];
			ans += acc;
		}
		else
		{
			sorted[k++] = arrb[j++];
			acc++;
		}
	}
	while (i <= mid)
	{
		sorted[k++] = arrb[i++];
		ans += acc;
	}
	while (j <= right)
	{
		sorted[k++] = arrb[j++];
	}
	for (i = left; i <= right; ++i)
	{
		arrb[i] = sorted[i];
	}
}