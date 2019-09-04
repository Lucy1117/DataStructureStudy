//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 2293번 문제
// n가지 종류의 동전으로 k원이 되도록 하는 문제.
// https://www.acmicpc.net/problem/2293

int a[101];
int d[10001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, k;
	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	d[0] = 1;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - a[i] >= 0)
			{
				d[j] += d[j - a[i]];
			}
		}
	}

	cout << d[k];

	return 0;
}
