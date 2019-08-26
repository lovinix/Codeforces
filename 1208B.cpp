#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int N, arr[2'001], cnt[2'001], num[2'001], ans;
vector<int> carr;

void sub(int u);
void add(int u);

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
		carr.emplace_back(arr[i]);
	}
	sort(carr.begin(), carr.end());
	carr.erase(unique(carr.begin(), carr.end()), carr.end());
	for (int i = 0; i < N; ++i)
		arr[i] = lower_bound(carr.begin(), carr.end(), arr[i]) - carr.begin();
	for (int i = 0; i < N; ++i)
		add(arr[i]);
	int ans = (num[1] == N ? 0 : N);
	int l = 0, r = 0;
	for (int i = 0; i < N; ++i)
		for (int j = i; j < N; ++j)
		{
			while (r <= j) { sub(arr[r++]); if (num[1] == (N - (j - i + 1))) ans = min(ans, j - i + 1); }
			while (r > j+1) { add(arr[--r]); if (num[1] == (N - (j - i + 1))) ans = min(ans, j - i + 1); }
			while (l < i) { add(arr[l++]); if (num[1] == (N - (j - i + 1))) ans = min(ans, j - i + 1); }
			while (l > i) {	sub(arr[l--]); if (num[1] == (N - (j - i + 1))) ans = min(ans, j - i + 1); }
		}
	cout << ans << "\n";
}

void sub(int u)
{
	if(cnt[u])
		num[cnt[u]]--;
	num[--cnt[u]]++;
}

void add(int u)
{
	if(cnt[u])
		num[cnt[u]]--;
	num[++cnt[u]]++;
}

