#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
��⣺��չŷ������㷨��������
�ο���https://www.acwing.com/blog/content/17/
*/

typedef long long LL;

LL extend_gcd(LL a, LL b, LL &x, LL &y)	// ��չŷ������㷨
{
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	LL q = extend_gcd(b, a % b, x, y);
	int t = x;
	x = y;
	y = t - a / b * y;
	return q;
}

int main()
{
	int N;
	cin >> N;
	while (N--) {
		LL a, b, c, x, y;
		cin >> a >> b >> c;
		int d = extend_gcd(a, b, x, y);  // ax + by = d
		if(c > a && c > b || c % d) {  // ���������
			cout << 0 << endl;
			continue;
		}
		if(c == a || c == b) {  // 1�β������
			cout << 1 << endl;
			continue;
		}

		if(y > 0) {  // xy < 0����x > 0��x < 0ʱ��a��b��x��y������
			swap(x, y);
			swap(a, b);
		}
		
		// ʹax + by = c ��d��c�����ӣ���������ʽ��ax + by = d����ͬʱ����c / d��
		x *= c / d;  
		y *= c / d;
		
		LL a2 = a / d, b2 = b / d;
		LL k = x / b2;
		x -= k * b2;  // ʹ����(x, y)��ӽ�0��x > 0ʱ�������⣩
		y += k * a2;
		
		LL res;
		if(c > a) // ���(1)
			res = 2 * (x - y);
		else // ���(2)
			res = 2 * (x - y - 1);
		
		x -= b2;  // ʹ����(x, y)��ӽ�0��y > 0ʱ�������⣩
		y += a2;
		if(c > b) // ���(1)
			res = min(res, 2 * (y - x));  // ���ķ����м���x > 0������y > 0
		else // ���(2)
			res = min(res, 2 * (y - x - 1));
			
		cout << res << endl;
	}
	return 0;
}

/*
2
3 4 2
2 3 4
*/
