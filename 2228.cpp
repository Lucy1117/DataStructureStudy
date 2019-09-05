//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

// 2228번 문제
// N개의 수로 이루어진 1차원 배열에서 M개의 구간을 선택해서,
// 구간에 속한 수들의 총 합이 최대가 되도록
// 구간은 한 개 이상의 연속된 수들로, 다른 구간끼리 인접해 있으면 안됨.
// https://www.acmicpc.net/problem/2228

int a[101];
int d[101][101];
bool c[101][101];
int minn = (-32768 * 101);

int go(int i, int j)
{
	if (j == 0)
	{
		return 0;
	}
	if (i <= 0)
	{
		return minn;
	}
	if (c[i][j])
	{
		return d[i][j];
	}
	c[i][j] = true;
	int& ans = d[i][j];
	ans = go(i - 1, j); // 마지막 수 없이 그룹을 했을 때
	int sum = 0;
	for (int k = i; k >= 1; k--)
	{
		sum += a[k];
		int temp = go(k - 2, j - 1) + sum; // 마지막 수를 하나의 그룹으로 했을 때
		if (ans < temp)
		{
			ans = temp;
		}
	}
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}

	cout << go(n, m) << '\n';

	return 0;
}
