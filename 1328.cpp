//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1328�� ����
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

	for (int i = 1; i <= n - 1; i++)
	{
		for (int j = 1; j <= l; j++)
		{
			for (int k = 1; k <= r; k++)
			{
				if (j + 1 <= l)
				{ // ���ʿ� ���� 1�� �߰��ϴ� ���
					d[i + 1][j + 1][k] += d[i][j][k];
					d[i + 1][j + 1][k] %= mod;
				}
				if (k + 1 <= r)
				{ //�����ʿ� ���� 1�� �߰��ϴ� ���
					d[i + 1][j][k + 1] += d[i][j][k];
					d[i + 1][j][k + 1] %= mod;
				}
				// ���̿� ���� 1�� �߰��ϴ� ���. �߰��� �� �ִ� ��찡 n-1(i-1)�� ����
				d[i + 1][j][k] += d[i][j][k] * (i - 1);
				d[i + 1][j][k] %= mod;
			}
		}
	}
	cout << d[n][l][r] << '\n';

	return 0;
}
