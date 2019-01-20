#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
��⣺
1.�����L <= maxLen����ô��ֱ�����L
2.��������̰��˼�룬�ȱ�����������������������������֮�������
����Ϊ�ߵ�Խ���·���ظ��Ľڵ��ߵľ�Խ�ࣩ������ʱ��Ҫ��������maxLen�Ĳ��� 
����min(n, 1 + maxLen + (L - maxLen) / 2)
*/

int parent[51];
int dp[101];

int main() 
{
	int n, L;
    scanf("%d%d", &n, &L);
    for(int i = 0; i < n - 1; i++) {
        scanf("%d", &parent[i]);
    }
    int mx = 0;		// ���������� 
    for(int i = 0; i < n - 1; i++) {
        dp[i + 1] = dp[parent[i]] + 1;
        mx = max(mx, dp[i + 1]);
    }
    int d = min(L, mx);
    printf("%d\n", min(n, 1 + d + (L - d)/2));
	return 0;
}

/*
5 2
0 1 2 3
*/
