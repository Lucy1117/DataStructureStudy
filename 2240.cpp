//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 2240�� ����
// �ڵ� ����
// �ڵδ� n�ʵ��� ��������, �޴� ����� �ִ� m���� ������.
// https://www.acmicpc.net/problem/2240

int a[1001];
int d[10001][31];
int n, m;

int go(int sec, int turn)
{
	if (sec == n + 1 && turn <= m)
	{ // �ð� �ʰ� �����µ� turn ���� ���ڶ� ��
		return 0;
	}
	if (turn > m)
	{ // turn ���� m���� Ŀ���� ��
		return 0;
	}
	if (d[sec][turn] != -1)
	{
		return d[sec][turn];
	}
	int where = turn % 2 + 1; // 0�̸� 1, 1�̸� 2
	int& ans = d[sec][turn];
	ans = max(go(sec + 1, turn), go(sec + 1, turn + 1)) + (where == a[sec] ? 1 : 0);
	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));

	cout << max(go(1, 0), go(1, 1)) << '\n'; // 1���� �����ϴ� ���� 2���� �����ϴ� ��� ����

	return 0;
}
