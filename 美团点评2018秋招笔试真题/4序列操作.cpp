#include <cstdio>
#include <iostream>
using namespace std;

const int N = 100000;

struct Node {
    int prev; // ǰһ������
    int post; // ��һ������
};
Node nodes[N + 1];

void Print(Node* nodes, int n, int head)
{
    int now = head;
    while (now != n + 1) {
        printf("%d\n", now);
        now = nodes[now].post; // ������
    }
}
int main()
{
    int n = 0;
    scanf("%d", &n);
    // prevΪ0��ʾ��ʼ
    // postΪn+1��ʾ����
    for (int i = 1; i <= n; ++i) {
        nodes[i].prev = i - 1;
        nodes[i].post = i + 1;
    }
    // ��������
    int head = 1;
    int m = 0;
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
        int move = 0;
        scanf("%d", &move);
        if (move == head)
            continue; // ���Ҫ�ƶ��������Ѿ���ͷ�ڵ㣬������
        int prev = nodes[move].prev;
        int post = nodes[move].post;
        nodes[prev].post = post;
        nodes[post].prev = prev;
        nodes[move].prev = 0;
        nodes[move].post = head;
        nodes[head].prev = move;
        head = move; //  ����ͷ�ڵ��±�
    }
    Print(nodes, n, head);
    return 0;
}

/*
5 3 
4 
2
5 
*/
