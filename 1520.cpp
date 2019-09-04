//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 1520번 문제
// 내리막길 문제
// https://www.acmicpc.net/problem/1520

// Top-down 형식

int n, m;
int a[500][500];
long long d[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

int go(int x, int y)
{
	if (x == n - 1 && y == m - 1)
	{
		return 1;
	}
	if (d[x][y] != -1)
	{
		return d[x][y];
	}
	long long& ans = d[x][y];
	ans = 0;
	for (int k = 0; k < 4; k++)
	{
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (a[x][y] > a[nx][ny])
			{
				ans += go(nx, ny);
			}
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));

	cout << go(0, 0) << '\n';

	return 0;
}
