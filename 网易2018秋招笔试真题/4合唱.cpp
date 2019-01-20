#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

/*
���⣺��һ�������Ԫ�طָ������ˣ�˳�����ң�ÿ���˵��Ѷ�Ϊ������Ԫ��֮�ͣ��������˵���С�ѶȺ�
��⣺
	dp[i][j] ��ʾ��ǰСQ������ i ��������ţ��ʿ������ j ���������ѶȺ�
	�ݹ�ʽ��
		dp[i][j] = dp[i-1][j] + abs(v[i] - v[i-1]), 			j < i - 1 
		dp[i][i-1] = min{ dp[i-1][k] + abs(v[i] - v[k]) }, 		k < i - 1 
	��ʼ����
		��ʼ���������ǰ�� i ��������������һ����ֻ����һ�������һ��������ʣ�µ�����������һ���˳� 
		dp[i][0] = dp[i-1][0] + abs(v[i] - v[i-1]), 			i �� 2 
		dp[i][i-1] = dp[i-1][i-2] + abs(v[i-1] - v[i-2]), 		i �� 2
*/

const int maxn = 2010;
int dp[maxn][maxn];
int acc[maxn], v[maxn];
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &v[i]);
	}
	if (n < 3) {
		printf("0\n");
	} else {
		dp[1][0] = 0;
		acc[1] = 0;
		for (int i = 2; i < n; i++) {
			acc[i] = acc[i - 1] + abs(v[i - 1] - v[i - 2]);
			dp[i][i - 1] = acc[i];
			for (int j = 0; j < i - 1; j++) {
				dp[i][j] = dp[i - 1][j] + abs(v[i] - v[i - 1]);
				dp[i][i - 1] = min(dp[i][i - 1], dp[i - 1][j] + abs(v[i] - v[j]));
			}
		}
		int mins = dp[n - 1][0];
		for (int i = 1; i < n - 1; i++) {
			if (dp[n - 1][i] < mins) {
				mins = dp[n - 1][i];
			}
		}
		printf("%d", mins);
	}
	return 0;
}

/*
5
1 5 6 2 1
*/
