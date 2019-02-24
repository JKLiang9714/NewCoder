#include <cstdio>
#include <iostream>
using namespace std;

/*
题解：首先，确定面值𝑛最多能有多少种面值。然后从大到小，每种面值的硬币用一个，剩下的全部用面值为1的硬币填充
*/

int main()
{
    int n = 0;
    scanf("%d", &n);

    const int coins[] = { 0, 1, 2, 5, 10, 20, 50, 100 }; // 硬币种类
    int sum[8]; // 下标代表币种数
    sum[0] = 0;
    // 统计每种不同种类组合最小总和
    for (int i = 1; i < 8; ++i) {
        sum[i] = coins[i] + sum[i - 1];
    }

    for (int i = 7; i > 0; --i) {
        if (sum[i] <= n) {
            // i表示使用币种数
            // n - sum[i]表示剩余使用1元的数目
            printf("%d %d\n", i, n - sum[i] + i);
            break;
        }
    }
    return 0;
}

/*
10
*/
