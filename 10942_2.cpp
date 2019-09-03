//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

//Top-Down
//팰린드롬 문제 go()함수로 푼 것
//https://www.acmicpc.net/problem/10942

int d[2000][2000];
int a[2000];

int go(int i, int j)
{
	if (i == j) //한 자리 수
	{
		return 1;
	}
	else if (i + 1 == j) // 두 자리 수
	{
		if (a[i] == a[j])
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	if (d[i][j] != -1)
	{
		return d[i][j];
	}
	if (a[i] != a[j])
	{
		return d[i][j] = 0;
	}
	else
	{
		return d[i][j] = go(i + 1, j - 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));

	int m;
	cin >> m;
	while (m--)
	{
		int s, e;
		cin >> s >> e;
		cout << go(s - 1, e - 1) << '\n';
	}

	return 0;
}
