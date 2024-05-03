#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
#define LL long long
const int N = 1e5 + 5;

int a[N], sum[N], n;
int temp[N];

LL mergesort(int l, int r)
{
	if (l >= r) return 0;
	int mid = (l + r) >> 1;
	LL ans = mergesort(l, mid) + mergesort(mid + 1, r);
	int ll = l, rr = mid + 1;
	int cnt = 0;
	while (ll <= mid && rr <= r)
	{
		if (sum[rr] >= sum[ll])
		{
			temp[++cnt] = sum[ll++];
		}
		else
		{
			ans += ll - l;
			temp[++cnt] = sum[rr++];
		}
	}
	while (ll <= mid)
	{
		temp[++cnt] = sum[ll++];;
	}
	while (rr <= r)
	{
		ans += mid - l + 1;
		temp[++cnt] = sum[rr++];
	}
	for (int i = 1; i <= cnt; i++)
	{
		sum[l + i - 1] = temp[i];
	}
	return ans;
}

LL check(int x)
{
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + (a[i] >= x ? 1 : -1);
		if (sum[i] >= 0)
			ans++;
	}
	LL t= ans + mergesort(1, n);
	cout<<x<<"-"<<t<<"\n";
	return t;
}


int main()
{
	freopen("C:\\Users\\30886\\Desktop\\in.txt", "r", stdin);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int l = 1, r = 1e9+10;
	LL aim = (1LL + n) * n / 2;
	cout<<(aim + 1) / 2<<"  -\n";
	while (l < r)
	{
		int mid = (l + r + 1) / 2;
		if (check(mid) >= (aim + 1) / 2)
		{
			l = mid;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}
