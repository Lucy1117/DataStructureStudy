//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
using namespace std;

// 1720 ����
// Ÿ�� �ڵ�
// n�� �־����� ��ü Ÿ�� �ڵ��� ������ ���ϴ� ���α׷��� �ۼ�(�������� �������� �� ����)
// 2 * n ũ���� ���� 1*2, 2*1 �Ǵ� 2*2 Ÿ�Ϸ� ä����� �Ѵ�.
// �¿찡 �Ȱ��� Ÿ���� ���� �ϳ��̰�, �������� �������� ���� �ΰ��� �� ���� �̿�
// https://www.acmicpc.net/problem/1720

long long a[31]; // ����
long long d[31]; // ������

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
		if (i % 2 == 1) // Ȧ��
		{
			b = a[(i - 1) / 2]; // �¿찡 �Ȱ��� Ÿ���� ��(��Ī)
		}
		else // ¦��
		{
			b = a[i / 2] + 2 * a[(i - 2) / 2]; // �¿찡 �Ȱ��� Ÿ���� ��(��Ī)
		}
		d[i] = (a[i] + b) / 2;
	}

	cout << d[n] << '\n';

	return 0;
}
