#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int res = 0; // ����Ӵ�����

    for (int i = 0; i < s.size(); i++) {
        for (int j = i + 1; j < s.size(); j++) {
            int len = 0;    // ��ǰ�ظ��ַ�����
            int now = i;    // ���浱ǰ�±�
            int post = j;   // ���浱ǰ�±�
            while (s[now] == s[post]) {
                now++;
                post++;
                len++;
            }
            res = max(len, res); // ����ظ��ִ�����
        }
    }
    printf("%d\n", res);
    return 0;
}

/*
ababcdabcefsgg
*/
