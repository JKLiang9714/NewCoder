#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
��⣺����3�����
1��ȫ������ 2��ȫ�Ǹ��� 3�������и���ǰ���������ֻ��Ҫȡ������3������˼��ɡ�
�����������õ�����϶���������С�ĸ�����˵õ�һ��������Ȼ���һ������������ˣ������õ������������������˵Ľ���нϴ���Ǹ��϶�����������
����ת�������������������������max1��max2��max3��������С����min1��min2��Ȼ��Ƚ�max1*max2*max3��max1*minl*min2�Ĵ�С��
*/

int main() 
{
	int n;
   	scanf("%d", &n);
   	long long nums[101];
   	fill_n(nums, n, 0);
   	for (int i = 0; i < n; i++) {
       	scanf("%lld", &nums[i]);
   	}
   	sort(nums, nums + n);
   	long long m = max(nums[n-1]*nums[n-2]*nums[n-3], nums[n-1]*nums[0]*nums[1]);
   	printf("%lld\n", m);
	return 0;
}

/*
4
3 4 1 2
*/
