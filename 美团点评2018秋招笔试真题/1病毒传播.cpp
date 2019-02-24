#include <cstdio>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int N = 1000;
vector<int> vec[N + 1]; // �ڽӱ��±��ʾ����

int main()
{
    int n = 0; // ������
    int m = 0; // ����
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; ++i) {
        int u = 0;
        int v = 0;
        scanf("%d%d", &u, &v);
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    int k = 0;
    int t = 0;
    scanf("%d%d", &k, &t);
    set<int> S;
    for (int i = 0; i < k; ++i) {
        int s;
        scanf("%d", &s);
        S.insert(s);
    }
    bool has = false;
    for (int v : S) {
        set<int> infect;
        queue<int> q; // �������
        int visited[N + 1]; // �����Ƕ����Ƿ��ѷ���
        fill_n(visited, n + 1, -1); // ��ʼ��Ϊδ����
        infect.insert(v);
        visited[v] = 0; // ���v�Ѿ�����
        q.push(v); // ���v
        while (!q.empty()) { // ���зǿ�
            int now = q.front(); // ȡ������Ԫ��
            q.pop(); // ����Ԫ�س���
            for (int i = 0; i < vec[now].size(); i++) { // ����v���ڽӵ�
                int post = vec[now][i]; // ȡ���ڽӵ�
                if (visited[post] == -1 && visited[now] < t) { // �ж��ڽӵ��Ƿ����
                    visited[post] = visited[now] + 1; // ����ڽӵ��ѷ���
                    infect.insert(post);
                    q.push(post); // �ڽӵ����
                }
            }
        }
        if (S == infect) {
            printf("%d ", v);
            has = true;
        }
    }
    if (!has)
        printf("-1\n");
    return 0;
}

/*
4 3
3 2
1 2
1 4
3 2
4 2 1
*/
