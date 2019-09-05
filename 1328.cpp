//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// 1328번 문제
// 고층 빌딩
// 빌딩의 개수 n과 가장 왼쪽에서 보았을 때 보이는 빌딩의 수 L
// 가장 오른쪽에서 봤을 때 보이는 빌딩의 수 R이 주어졌을 때
// 가능한 빌딩 순서의 경우의 수를 구하는 프로그램
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
				{ // 왼쪽에 빌딩 1을 추가하는 경우
					d[i + 1][j + 1][k] += d[i][j][k];
					d[i + 1][j + 1][k] %= mod;
				}
				if (k + 1 <= r)
				{ //오른쪽에 빌딩 1을 추가하는 경우
					d[i + 1][j][k + 1] += d[i][j][k];
					d[i + 1][j][k + 1] %= mod;
				}
				// 사이에 빌딩 1을 추가하는 경우. 추가할 수 있는 경우가 n-1(i-1)개 존재
				d[i + 1][j][k] += d[i][j][k] * (i - 1);
				d[i + 1][j][k] %= mod;
			}
		}
	}
	cout << d[n][l][r] << '\n';

	return 0;
}
