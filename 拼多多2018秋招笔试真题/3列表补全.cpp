#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() 
{
	int offset = 0; // ƫ����
	int n = 0;      // Ԫ������
  	int l1 = 0;     // �б�L1����
 	int l2 = 0;     // �б�L2����
  	scanf("%d%d%d%d", &offset, &n, &l1, &l2);

  	int startA = min(l1, max(0, offset));
  	int endA = max(0, min(l1, offset + n));
  	int startB = min(l2, max(0, offset - l1));
  	int endB = max(0, min(l2, offset + n - l1));
  	printf("%d %d %d %d\n", startA, endA, startB, endB);
	return 0;
}

/*
2 4 4 4
*/
