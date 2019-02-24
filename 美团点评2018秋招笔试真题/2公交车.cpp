#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

/*
��⣺
�ѹ���������һ��ͼ�ϵĽڵ㣬��Ϊվ��ı�Ŵ�1��n���������ı�Ŵ�1��m�������ظ������ԣ��ѹ������ı�Ÿ�Ϊ��n+1��n+m
�����ɴ�վ��1��n��̾��롣ע��ÿ��վ���м������˹������ڵ㣬������ľ���Ҫ����2
*/

const int N = 200002;
vector<int> vec[N]; // ��1��ʼ
queue<int> q; // �������
int visited[N]; // �����Ƕ����Ƿ��ѷ���

int main()
{
    int n = 0; // վ����
    int m = 0; // ��������
    scanf("%d%d", &n, &m);
    // ��ͼͬһ��������ͨ���ĵ㽨һ���ߵ������������ĳ���㣬�ٴӳ���㽨һ���ߵ���Щ��
    for (int i = 1; i <= m; i++) {
        int t = 0;
        scanf("%d", &t); // ������������վ����
        for (int j = 1; j <= t; j++) {
            int a = 0;
            scanf("%d", &a); // ������������վ��
            vec[a].push_back(i + n); // ͬһվ�㾭���Ĺ�����
            vec[i + n].push_back(a); // ͬһ��������ͨ����վ��
        }
    }
    fill_n(visited, N, -1); // ��ʼ��Ϊδ����
    visited[1] = 0; // ���v�Ѿ�����
    q.push(1); // ���v
    while (!q.empty()) { // ���зǿ�
        int now = q.front(); // ȡ������Ԫ��
        q.pop(); // ����Ԫ�س���
        for (int i = 0; i < vec[now].size(); i++) { // ����v���ڽӵ�
            int post = vec[now][i]; // ȡ���ڽӵ�
            if (visited[post] == -1) { // �ж��ڽӵ��Ƿ����
                visited[post] = visited[now] + 1; // ����ڽӵ��ѷ���
                q.push(post); // �ڽӵ����
            }
        }
    }
    if (visited[n] == -1)
        printf("-1\n");
    else
        printf("%d\n", visited[n] / 2);
}

/*
5 3
3 1 2 3
3 3 4 2
3 3 5 4
*/
