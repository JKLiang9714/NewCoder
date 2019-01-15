#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

/*
��⣺
	a^b = c^d��
	������ȵ������ 
		1) ����Ϊ1���� 1^b = 1^d �������n * n 
		2) ������Ϊ1���� a^b = a^b �������(n - 1) * n
	��������ȵ������ 
		���(i^x)^b = (i^y)^d��i^x <= n��j^y<=n 
		����i, ȷ��x��y��ȡֵ��Χ
		����x��y��ȡ��x��y�����Լ���ŵ�������i��ָ��
*/

const int MOD = 1000000007;

int gcd (int a, int b) {
    return (a % b == 0) ? b : gcd(b, a % b);
}

int main() 
{
	int n;
	scanf("%d", &n);
	long long ans = (long long)(n * n + (n - 1) * n) % MOD;
	// ��������ȵ������������ (i^x)^b = (i^y)^d������ x!=y �� i>1
	set<int> s;
	for (int i = 2; i * i <= n; i++) {
		if (s.find(i) != s.end()) continue; 
		int tmp = i, cnt = 0;
		// ���������ĵ�����cntΪָ��x��y��ȡֵ���� 
		while (tmp <= n) {
			s.insert(tmp);
			tmp *= i;
			cnt++;
		}
		// ��ͬ�Ĺ�Լ�����ŵ����� 
		for (int x = 1; x <= cnt; x++) {
			for (int y = x + 1; y <= cnt; y++) {
				ans = (ans + n / (y / gcd(x, y) ) * 2 ) % MOD;
			}
		} 
	}
	printf("%d\n", ans);
	return 0;
}

/*
2
*/ 
