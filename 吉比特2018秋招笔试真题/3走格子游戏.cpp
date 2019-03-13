#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

/*
��⣺
��̬�滮���⣬״̬s(x,y)Ϊ��λ��Ϊ(x,y)ʱ����Ŀ����������С�ж������κ�����£���ǰ�ж�������С��1�������ɵ�״̬ת�Ʒ���Ϊ��
if x==col-1&&y==row-1
  s(x,y)=max(1-grid[x][y],1)
if x==col-1
  s(x,y)=max(s(x,y+1)-grid[x][y],1)
if y==row-1
  s(x,y)=max(s(x+1,y)-grid[x][y],1)
else
  s(x,y)=max(max(s(x,y+1)-grid[x][y],s(x+1,y)-grid[x][y]),1)

ΪʲôҪ��ȥgrid[x][y]?
	��Ϊ[x][y]�����ɸ�������ʾ��ǰ���������ж���������ʾ�����ж����������С�ж�����������ֵ����Ҫ��ʼ�ж���С��������ֵ����ʾ��Ҫ��ʼ�ж�����
Ϊʲô��1�Ƚ�?
	С��1��Ϸʧ�ܣ���������Ϊ1��
*/
int dp[1000][1000];

int solve(int x, int y, vector<vector<int> > & grid) {
	int row = (int)grid.size();
	int col = (int)grid[0].size();
	if (0 != dp[x][y]) return dp[x][y];
	int val = grid[y][x];
	if (x == col - 1 && y == row - 1) // ��������һ��λ��(���½�)
		return dp[x][y] = max(1 - val, 1);
	else if (x == col - 1) // �������һ�У�ֻ������
		return dp[x][y] = max(solve(x, y + 1, grid) - val, 1);
	else if (y == row - 1) // �������һ�У�ֻ������
		return dp[x][y] = max(solve(x + 1, y, grid) - val, 1);
	else {
		int res1 = max(solve(x, y + 1, grid) - val, 1);// ѡ������
		int res2 = max(solve(x + 1, y, grid) - val, 1);// ѡ������
		return dp[x][y] = min(res1, res2);
	}
}

int main() {
	int M, N;
	scanf("%d%d", &M, &N);
	vector<vector<int> > grid;
	for (int i = 0; i < M; i++) {
		vector<int> row;
		for (int j = 0; j < N; j++) {
			int K;
			scanf("%d", &K);
			row.push_back(K);
		}
		grid.push_back(row);
	}
	printf("%d\n", solve(0, 0, grid));
	return 0;
}

/*

*/
