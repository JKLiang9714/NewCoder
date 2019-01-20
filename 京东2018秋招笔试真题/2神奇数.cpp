#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

/*
���⣺�ж�һ�����Ƿ��ܲ�������������ǵĺ����
��⣺�����ִ�ɢ����arry���飬֮����01�������ж���װ����������һ���Ƿ����
*/

bool isNum(int x) {
    vector<int> vec;
    int num = x, half = 0;
    while (num) {
        vec.push_back(num % 10);
        half += num % 10;
        num /= 10;
    }
    // ��Ϊ�����Ĳ��������
    if (half % 2 != 0) return false;
    half /= 2;
    vector<int> dp(half + 1);
    for (int i = 0; i < vec.size(); i++) {
        for (int j = half; j >= vec[i]; j--) {
            dp[j] = max(dp[j], dp[j - vec[i]] + vec[i]);
        }
    }
    return dp[half] == half;
}

int main()
{
    int l, r;
    scanf("%d%d", &l, &r);
    int cnt = 0;
    for (int i = l; i <= r; i++) {
        if (isNum(i)) {
            cnt++;
        }
    }
    printf("%d\n", cnt);
    return 0;
}

/*
6354 234363
*/