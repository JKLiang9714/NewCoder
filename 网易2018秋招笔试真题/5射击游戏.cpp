#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
���⣺
	����һ�ѵ㣬���������ഹֱ���ߣ�����ܸ��Ƕ��ٵ�
��⣺
	��ѡ��3�������ߵĵ㣬ǰ�����㹹��һ��ֱ�ߣ�����һ���㹹��һ����ֱ��ǰһ��ֱ�ߵ�ֱ�ߣ�
	Ȼ��ö��ʣ�µĵ��Ƿ������������ϣ��������ֵ������
*/

const int MAXN = 51;
int x[MAXN], y[MAXN];

int main() 
{
	int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]); 
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &y[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            for (int k = 0; k < n; k++) {
                if (i == k || j == k) continue;
                if ((y[k] - y[j]) * (x[i] - x[j]) == (y[i] - y[j]) * (x[k] - x[j])) continue;
				int nums = 3;
                for (int l = 0; l < n; l++) {
                    if (i == l || j == l || k == l) continue;
                    if ((y[i] - y[l]) * (x[i] - x[j]) == (y[i] - y[j]) * (x[i] - x[l]) || 
						(y[j] - y[i]) * (y[k] - y[l]) == (x[k] - x[l]) * (x[i] - x[j])) {
                        nums++;
                    }
                }
				res = max(res, nums);
            }
        }
    }
    printf("%d\n", res);
	return 0;
}

/*
5
0 -1 1 1 -1
0 -1 -1 1 1
*/
