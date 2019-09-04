//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 1520번 문제
// 내리막길 문제
// https://www.acmicpc.net/problem/1520

// Bottom-up 형식

struct Cell
{
	int row, col, val;
};
int n, m;
int a[500][500];
long long d[500][500];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool cmp(const Cell& u, const Cell& v)
{
	return u.val < v.val;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;
	vector<Cell> v;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			v.push_back({ i,j,a[i][j] });
		}
	}
	sort(v.begin(), v.end(), cmp);
	d[n - 1][m - 1] = 1;
	for (int i = 0; i < v.size(); i++)
	{
		int x = v[i].row;
		int y = v[i].col;
		for (int k = 0; k < 4; k++)
		{
			int nx = x + dx[k];
			int ny = y + dy[k];
			if (0 <= nx && nx < n && 0 <= ny && ny < m)
			{
				if (a[nx][ny] < a[x][y])
				{
					d[x][y] += d[nx][ny];
				}
			}
		}
	}

	cout << d[0][0] << '\n';

	return 0;
}
