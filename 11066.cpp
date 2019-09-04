//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

// 11066번 문제
// 파일 합치기
// https://www.acmicpc.net/problem/11066

int a[501];
int s[501];
// s[] 파일 합치기는 연속된 파일만 합칠 수 있으므로 계산을 편리하게 하기 위해 사용
int d[501][501];
// d[i][j] = i번째 장부터 j번째 장까지 합쳤을 때, 필요한 최소 비용
// i번째 장부터 k 번째 장까지 합친 파일과 k+1번째 장부터 j번째 장까지 합치면 됨.

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

	int t; //테스트 개수
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
