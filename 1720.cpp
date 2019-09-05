//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

// 1720 문제
// 타일 코드
// n이 주어지면 전체 타일 코드의 개수를 구하는 프로그램을 작성(뒤집으면 같아지는 것 제외)
// 2 * n 크기의 판을 1*2, 2*1 또는 2*2 타일로 채우려고 한다.
// 좌우가 똑같은 타일의 수는 하나이고, 뒤집으면 같아지는 것은 두개씩 인 것을 이용
// https://www.acmicpc.net/problem/1720

long long a[31]; // 포함
long long d[31]; // 미포함

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	a[1] = 1;
	a[2] = 3;
	for (int i = 3; i <= 30; i++)
	{
		a[i] = a[i - 1] + a[i - 2] * 2LL;
	}
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++)
	{
		long long b = 0;
		if (i % 2 == 1) // 홀수
		{
			b = a[(i - 1) / 2]; // 좌우가 똑같은 타일의 수(대칭)
		}
		else // 짝수
		{
			b = a[i / 2] + 2 * a[(i - 2) / 2]; // 좌우가 똑같은 타일의 수(대칭)
		}
		d[i] = (a[i] + b) / 2;
	}

	cout << d[n] << '\n';

	return 0;
}
