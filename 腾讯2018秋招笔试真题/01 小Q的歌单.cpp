#include <iostream>
#include <cstdio>
using namespace std;

/*
��⣺�� a ���� i �׵ĸ��� *  �� b ���� j �׵ĸ���
�ѵ㣺������ϣ���Ҫ�ö�ά������ģ���������� C(n, m) 
*/

const int MAXN = 100;
const int MOD = 1000000007;
long long c[MAXN + 1][MAXN +1] = { 0 };

// �洢����� C(n, m) ��ֵ 
void init() {
	c[0][0] = 1;
	for (int i = 1; i <= MAXN; i++) {
		c[i][0] = 1;
		for (int j = 1; j <= MAXN; j++) {
			c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
		}
	}
}

int main() 
{
	int k, a, x, b, y;
	scanf("%d%d%d%d%d", &k, &a, &x, &b, &y);
	init();
	long long ans = 0;
	for (int i = 0; i <= x; i++) {
		// ���� a ��������� x ��ȡ i �� 
		// ���� b ��������� y ��ȡ (k - i * a) / b ��
		if (i * a <= k && (k - i * a) % b == 0 && (k - i * a) / b <= y) {
			ans = (ans + (c[x][i] * c[y][(k - i * a) / b]) % MOD) % MOD;
		}
	} 
	printf("%lld\n", ans);
	return 0;
}

/*
5
2 3 3 3
*/
