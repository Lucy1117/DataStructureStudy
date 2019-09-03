//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

// Bottom-Up
// �Ӹ���� ���� 
// https://www.acmicpc.net/problem/10942

int n;
int a[2000];
bool d[2000][2000];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		d[i][i] = true; //1������ 1����, 2������ 2���� ���� �� �ڸ� ��
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (a[i] == a[i + 1]) //�� �ڸ� ��
		{
			d[i][i + 1] = true;
		}
	}
	for (int k = 3; k <= n; k++)
	{
		for (int i = 0; i <= n - k; i++)
		{
			int j = i + k - 1;
			if (a[i] == a[j] && d[i + 1][j - 1])
			{
				d[i][j] = true;
			}
		}
	}
	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << d[s - 1][e - 1] << '\n';
	}

	return 0;
}
