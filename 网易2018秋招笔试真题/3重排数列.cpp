#include <iostream>
#include <cstdio>
using namespace std;

/*
���⣺��������A��ʹ�ö�������i������A[i] * A[i + 1]��4�ı���
��⣺
	˼·��
		1. ������4����������������˺󣬻���������4
		2. ������2����������4������ֻ�ܺ�������2����������4������˺󣬲�������4
		3. ��������2��4����������������˶���������4
	��ηţ�
		����2�����ȫ����һ�𣬽���1������͵�3����������
	������
		1 2 3 4 5 6 8 10 16 -> (2 6 10) (4 1) (8 3) (16 5)
*/

const int MAXN = 1e5;
int a[MAXN + 1];

int main() 
{
	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int mod2 = 0, mod4 = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] % 4 == 0) mod4++;
			else if (a[i] % 2 == 0) mod2++;
		}
		if (n - mod2 - mod4 <= mod4) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}

/*
4
3
1 10 100
4
1 2 3 4
8
1 2 3 4 5 6 8 10
9
1 2 3 4 5 6 8 10 16
*/
