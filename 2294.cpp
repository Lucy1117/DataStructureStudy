//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

// 2294번 문제
// n가지 종류의 동전으로 k원이 되도록 하는 값의 최소값을 구하는 문제.
// https://www.acmicpc.net/problem/2294

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

	for (int i = 0; i <= k; i++)
	{
		d[i] = -1;
	}
	d[0] = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			if (j - a[i] >= 0 && d[j - a[i]] != -1)
			{
				if (d[j] == -1 || d[j] > d[j - a[i]] + 1)
				{
					d[j] = d[j - a[i]] + 1;
				}
			}
		}
	}

	cout << d[k];

	return 0;
}
