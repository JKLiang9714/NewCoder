#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct ChildInfo {
	int child;    // �ӳ����±�
	int distance; // ���ӳ��еľ���
};

void dfs(vector<vector<ChildInfo> > &lnk, int u, vector<int> &seq) {
	for (int k = 0; k != lnk[u].size(); ++k) {
		dfs(lnk, lnk[u][k].child, seq);
	}
	seq.push_back(u);
}
int main() {
	int m = 0; // ���Ƶ�·�ܳ�������
	int n = 0; // ���и���
	while (scanf("%d%d", &m, &n) == 2) {
		vector<vector<ChildInfo> > lnk(n); // �±��Ǹ����У�Ԫ�����ӳ������������
		vector<int> in(n, 0);// �ӳ���ͳ��
		for (int i = 1; i < n; ++i) {
			int u = 0; // ������
			int v = 0; // �ӳ���
			int d = 0; // ����
			scanf("%d%d%d", &u, &v, &d);
			in[v]++;
			// ������
			lnk[u].push_back(ChildInfo{ v, d });
		}

		// ���Ҹ��ڵ�
		int root; // ���ڵ�
		for (int i = 0; i < n; ++i) {
			if (in[i] == 0) {
				root = i;
				break;
			}
		}

		// ������������г���˳��
		vector<int> seq;
		dfs(lnk, root, seq);

		// ͳ��
		vector<int> mem[n];
		for (int i = 0; i != n; ++i) {
			int u = seq[i];
			// ��һ���������ѡ��
			mem[u].push_back(0);
			// �ڶ��������ѡ��һ���ӳ���
			for (int k = 0; k != lnk[u].size(); ++k) {
				int v = lnk[u][k].child;
				int dist = lnk[u][k].distance;
				vector<int> memv = mem[v];
				for (auto &value : memv) {
					int d = value + dist;
					if (mem[u].end() == find(mem[u].begin(), mem[u].end(), d)) {
						mem[u].push_back(d);
					}
				}
			}
			// �����������ѡ�������ӳ���
			for (int k1 = 0; k1 != lnk[u].size(); ++k1)
				for (int k2 = k1 + 1; k2 != lnk[u].size(); ++k2) {
					int v1 = lnk[u][k1].child;
					int dist1 = lnk[u][k1].distance;
					vector<int> memv1 = mem[v1];
					int v2 = lnk[u][k2].child;
					int dist2 = lnk[u][k2].distance;
					vector<int> memv2 = mem[v2];
					for (auto &value1 : memv1)
						for (auto &value2 : memv2) {
							int d = value1 + dist1 + value2 + dist2;
							if (mem[u].end() == find(mem[u].begin(), mem[u].end(), d)) {
								mem[u].push_back(d);
							}
						}
				}
		}
		// �ҵ��������������ֵ
		int result = 0;
		for (auto &value : mem[root])
			if (value <= m) { // ����С�ڻ��Ƶ�·�ܳ�������
				result = max(result, value);
			}
		printf("%d\n", result);
	}
	return 0;
}

/*
5
5
0 1 1
0 2 2
0 3 3
0 4 4
*/
