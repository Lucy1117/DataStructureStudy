//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 11066�� ����
// ���� ��ġ��
// https://www.acmicpc.net/problem/11066

int a[501];
int s[501];
// s[] ���� ��ġ��� ���ӵ� ���ϸ� ��ĥ �� �����Ƿ� ����� ���ϰ� �ϱ� ���� ���
int d[501][501];
// d[i][j] = i��° ����� j��° ����� ������ ��, �ʿ��� �ּ� ���
// i��° ����� k ��° ����� ��ģ ���ϰ� k+1��° ����� j��° ����� ��ġ�� ��.

int go(int i, int j)
{
	if (i == j) {
		return 0;
	}
	if (d[i][j] != -1)
	{
		return d[i][j];
	}
	int& ans = d[i][j];

	for (int k = i; k <= j - 1; k++)
	{
		int temp = go(i, k) + go(k + 1, j) + s[j] - s[i - 1];
		if (ans == -1 || ans > temp)
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

	int t; //�׽�Ʈ ����
	cin >> t;

	while (t--)
	{
		memset(d, -1, sizeof(d));
		memset(s, 0, sizeof(s));
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			s[i] = s[i - 1] + a[i];
		}
		cout << go(1, n) << '\n';
	}


	return 0;
}
