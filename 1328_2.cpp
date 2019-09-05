//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1328�� ����_2
// ���� ����
// ������ ���� n�� ���� ���ʿ��� ������ �� ���̴� ������ �� L
// ���� �����ʿ��� ���� �� ���̴� ������ �� R�� �־����� ��
// ������ ���� ������ ����� ���� ���ϴ� ���α׷�
// https://www.acmicpc.net/problem/1328

long long d[101][101][101];
long long mod = 1000000007LL;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, l, r;
	cin >> n >> l >> r;
	d[1][1][1] = 1LL;

	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				d[i][j][k] = d[i - 1][j - 1][k] + d[i - 1][j][k - 1] + d[i - 1][j][k] * (i - 2);
				d[i][j][k] %= mod;
			}
		}
	}
	cout << d[n][l][r] << '\n';

	return 0;
}
