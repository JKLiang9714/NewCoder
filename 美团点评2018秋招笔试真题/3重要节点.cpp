#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1000;
vector<int> vec[N + 1]; //���ڽӱ����ʽ��ߣ��±��ʾ��㣬���ݱ�ʾ�յ�
vector<int> S_v[N + 1];
vector<int> T_v[N + 1];

int main()
{
    int n = 0; // ������
    int m = 0; // ����
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u = 0; // ���
        int v = 0; // �յ�
        scanf("%d%d", &u, &v);
        vec[u].push_back(v); // �����ϵ
    }

    // BFS
    for (int i = 1; i <= n; i++) { // ��������
        queue<int> q;
        q.push(i);
        while (!q.empty()) { // ������ʽBFS
            int now = q.front();
            q.pop();
            for (int j = 0; j < vec[now].size(); j++) { // ����now�ĺ�������
                int post = vec[now][j];
                if (find(S_v[i].begin(), S_v[i].end(), post) == S_v[i].end()) {
                    S_v[i].push_back(post);
                    T_v[post].push_back(i);
                    q.push(post); // ��¼�����ڵ�
                }
            }
        }
    }
    // ͳ�ƽ��
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (T_v[i].size() > S_v[i].size())
            ans++;
    }
    //������Ҫ�ڵ������
    printf("%d\n", ans);
    return 0;
}

/*
4 3
2 1
3 1
1 4
*/
