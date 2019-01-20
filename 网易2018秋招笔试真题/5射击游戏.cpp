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
    if (n <= 2) {
        printf("%d\n", n);
    } else {
        int res = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                int dx1 = x[j] - x[i];
                int dy1 = y[j] - y[i];
                for (int k = 0; k < n; k++) {
                    int cnt = 0;
                    if (i != k && j != k) {
                        for (int l = 0; l < n; l++) {
                            int dx2 = x[l] - x[i];
                            int dy2 = y[l] - y[i];
                            int dx3 = x[l] - x[k];
                            int dy3 = y[l] - y[k];
                            if (dy1 * dx2 == dy2 * dx1 || dy1 * dy3 == -dx3 * dx1) {
                                cnt++;
                            }
                        }
                    }
                    res = max(res, cnt);
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}

/*
5
0 -1 1 1 -1
0 -1 -1 1 1
*/
