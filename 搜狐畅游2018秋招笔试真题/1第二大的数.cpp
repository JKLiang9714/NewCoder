#include <iostream>
#include <cstdio>
using namespace std;

int main() 
{
	int n = 0;
	scanf("%d", &n);
	int max = -0xffffff;
	int sec_max = -0xffffff;
	while (n--) {
		int num = 0;
		scanf("%d", &num);
		if (max < num) { // ������ִ������ֵ
			sec_max = max;
			max = num;
		}
		else if (sec_max < num) { // ������ִ��ڵڶ���ֵ
			sec_max = num;
		}
	}
	printf("%d\n", sec_max);
	return 0;
}

/*
5
1 2 3 4 5
*/
