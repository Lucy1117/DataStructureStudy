//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 11049¹ø ¹®Á¦
// Çà·Ä °ö¼À ¼ø¼­¿¡ µû¶ó °ö¼À ¿¬»ê È½¼öÀÇ ÃÖ¼Ú°ªÀ» ±¸ÇÏ´Â ¹®Á¦
// https://www.acmicpc.net/problem/11049

int a[1000][2];
int d[1000][1000];

int go(int x, int y)
{
	if (d[x][y])
	{
		return d[x][y];
	}
	if (x == y)
	{
		return 0;
	}
	if (x + 1 == y)
	{
		return a[x][0] * a[x][1] * a[y][1]; // Çà·Ä °ö¼À ¿¬»ê È½¼ö °è»ê¹ý
	}
	int& ans = d[x][y];
	ans = -1;
	for (int k = x; k <= y - 1; k++)
	{
		int t1 = go(x, k);
		int t2 = go(k + 1, y);
		if (ans == -1 || ans > t1 + t2 + a[x][0] * a[k][1] * a[y][1])
		{
			ans = t1 + t2 + a[x][0] * a[k][1] * a[y][1];
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i][0] >> a[i][1];
	}

	cout << go(0, n - 1);

	return 0;
}
