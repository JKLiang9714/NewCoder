#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

/*
���⣺���ܷ��ҵ����� X��ż�� Y���� X * Y = N��2 <= N < 2^63
��⣺������˫ָ�룬ͷβָ��ÿ�γ˳� 2 
*/

int main() 
{
	int t;
	long long n;
	scanf("%d", &t);
	while (t--) {
		scanf("%lld", &n);
		if (n & 1) printf("No\n");
		else {
			long long x = n / 2, y = 2;
			while (!(x & 1)) {
				x /= 2;
				y *= 2;
			}
			printf("%lld %lld\n", x, y);
		}
	} 
	return 0;
}

/*
2
10
5
*/
