//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

// 2228�� ����
// N���� ���� �̷���� 1���� �迭���� M���� ������ �����ؼ�,
// ������ ���� ������ �� ���� �ִ밡 �ǵ���
// ������ �� �� �̻��� ���ӵ� �����, �ٸ� �������� ������ ������ �ȵ�.
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
	ans = go(i - 1, j); // ������ �� ���� �׷��� ���� ��
	int sum = 0;
	for (int k = i; k >= 1; k--)
	{
		sum += a[k];
		int temp = go(k - 2, j - 1) + sum; // ������ ���� �ϳ��� �׷����� ���� ��
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
