#include <iostream>
#include <cstdio>
using namespace std;

/*
ע�⣺�������⣬ҳ�Ŵ�0��ʼ
*/

int main() 
{
	int n = 0;
	scanf("%d", &n);
	int *nums = new int[n + 1];
	for (int i = 0; i < n; ++i) {
		scanf("%d", &nums[i]);
	}
	int page = 0; // ҳ��
	int size = 0; // ÿҳ��ʾ���ݸ���
	scanf("%d%d", &page, &size);
	if (page*size >= n) {
		printf("������ҳ��Χ\n");
	}
	for (int i = page * size; i < (page + 1)*size; ++i) {
		printf("%d\n", nums[i]);
	}
	return 0;
}

/*
6
1 2 3 4 5 6
1
2
*/
