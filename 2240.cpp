//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// 2240번 문제
// 자두 나무
// 자두는 n초동안 떨어지고, 받는 사람은 최대 m번만 움직임.
// https://www.acmicpc.net/problem/2240

int a[1001];
int d[10001][31];
int n, m;

int go(int sec, int turn)
{
	if (sec == n + 1 && turn <= m)
	{ // 시간 초가 지났는데 turn 수가 모자랄 때
		return 0;
	}
	if (turn > m)
	{ // turn 수가 m보다 커졌을 때
		return 0;
	}
	if (d[sec][turn] != -1)
	{
		return d[sec][turn];
	}
	int where = turn % 2 + 1; // 0이면 1, 1이면 2
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

	cout << max(go(1, 0), go(1, 1)) << '\n'; // 1에서 시작하는 경우와 2에서 시작하는 경우 각각

	return 0;
}
