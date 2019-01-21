#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
���⣺��ǰ��0�㣬Ҫȥx�㣬����+1��-1��*2��������߷�
��⣺�ݹ�
	xΪż��ʱ��һֱ��*2����
	xΪ����ʱ����Ҫ����һ������+1��*2����-1��*2
*/

int countStep(int x) {
	if (x < 0) x = -x;
	if (x == 0 || x == 1 || x == 2) return x;
	int step;
	if (x % 2 == 0) step = countStep(x / 2) + 1;
	else {
		int s1 = countStep((x + 1) / 2) + 2;
		int s2 = countStep((x - 1) / 2) + 2;
		step = min(s1, s2);
	}
	return step;
}

int main() 
{
	int x;
	scanf("%d", &x);
	int res = countStep(x);
	printf("%d\n", res);
	return 0;
}

/*
3
*/
