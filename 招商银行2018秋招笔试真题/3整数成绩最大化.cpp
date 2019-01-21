#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;

/*
���⣺һ�������ֽ�Ϊ������������֮�ͣ�ʹ����Щ�����ĳ˻���󻯣�������˻�
��⣺dp���鱣���м�����dp[i] = max(dp[i], dp[j] * dp[i - j])
*/

const int MAXN = 1e5;
int dp[MAXN] = { 0 };

int main()
{
    int n, res;
    scanf("%d", &n);
    if (n < 2) res = 0;
    else if (n == 2) res = 1;
    else if (n == 3) res = 2;
    else {
        int* dp = new int[n + 1];
        dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for (int i = 4; i <= n; i++) {
            int current_max = -1;
            for (int j = 1; j <= i / 2; j++) {
                if (dp[j] * dp[i - j] > current_max) {
					current_max = dp[j] * dp[i - j];
				}
            }
            dp[i] = current_max;
        }
        res = dp[n];
    }
	printf("%d\n", res);
    return 0;
}

/*

*/
