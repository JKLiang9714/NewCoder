#include <iostream>
#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*ע�⣺��������*/

int solve(int* nums, int n) {
	int *counts = new int[n+1]; // ���ÿ��С�������ǹ���
	fill_n(counts, n, 0); // �������
	counts[0] = 1;

	for (int i = 1; i < n; ++i) {// �������з�ֵ
		if (nums[i] == nums[i - 1]) { // ��ֵ����ǹ����
			counts[i] = counts[i - 1];
		}
		else if (nums[i] > nums[i - 1]) { // ��ǰѧ����ǰһ��ѧ����ֵ�ߣ����1���ǹ�
			counts[i] = counts[i - 1] + 1;
		}
		else { // ��ǰѧ����ǰһ��ѧ����ֵ��
			if (counts[i - 1] > 1) { // ǰһ��ѧ���ǹ�������1
				counts[i] = counts[i - 1] - 1; // ��ǰѧ����ǰһ��ѧ���ǹ�����1
			}
			else { // ���ǰһ��ѧ���ǹ���Ϊ1
				counts[i] = 1;// ��ǰѧ���ǹ���Ϊ1
				for (int j = i; j >= 1; --j) {// ��ǰ�������߷�����ѧ���ǹ�����1
					if (nums[j - 1] < nums[j]) break; // ֱ�����������͵�ѧ��Ϊֹ
					if (nums[j - 1] >= nums[j]) counts[j - 1]++;
				}
			}
		}
	}
	// ͳ�����е��ǹ�
	return accumulate(counts, counts + n, 0);
}

int main() {
	vector<int> nums;
	int num = 0;
	while (cin >> num) {
		nums.push_back(num);
		char c = cin.peek(); // ��ȡ�¸��ַ�
		if ('\n' == c) break; // �س���ʾ�������
		cin.ignore(1, ','); // ��ȥ���ŷָ��
	}
	printf("%d\n", solve(nums.data(), nums.size()));
	return 0;
}

/*
0,1,0
*/
