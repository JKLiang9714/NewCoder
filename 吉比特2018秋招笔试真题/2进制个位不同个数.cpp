#include <iostream>
#include <cstdio>
using namespace std;

/*
���⣺�����������������������������Ƹ�ʽ�ж��ٸ���λ��ͬ
��⣺ ������������򣬽����Ľ�������һ�����������1��λ����1����ֱ��Ϊ�㣬���Ƕ����Ʋ�ͬλ��������
*/

int main() 
{
	int m, n;
	scanf("%d%d", &m, &n);
	int num = m ^ n;
	int count = 0;
	while (num) {
		num = num & (num - 1);
		count++;
	}
	printf("%d\n", count);
	return 0;
}

/*
22 33
*/
