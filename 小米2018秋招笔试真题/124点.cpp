#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
using namespace std;

/*
��⣺�ݹ飬ѡ�벻ѡ��ʱ�临�Ӷ�Ϊ 2^n��n��ൽ30
*/

int a[30];
int n;
set<vector<int>> res;

// ��ȱ���
void DFS(int sum, int pos, vector<int> path) {
	if (pos == n + 1) return;
    if (sum > 24) return;
	if (sum == 24) {
		res.insert(path);
		return;
	}
	DFS(sum, pos + 1, path);   // ��ѡ��pos
	path.push_back(a[pos]);       // ѡ��pos
	DFS(sum + a[pos], pos + 1, path);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
	vector<int> path;
	DFS(0, 0, path); // ��ʼ��Ϊ0����0��ʼ
	printf("%d\n", (int)res.size());
	return 0;
}

/*
4
1 2 22 23
*/
