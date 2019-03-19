#include <iostream>
#include <cstdio>
using namespace std;

/*
��⣺
����������ڵ㲻��ͬһ���������棬��ô������ĸ��ڵ�������ǵĹ�ͬ��͸��ڵ㡣
���������������������ô������������������Ǹ��ڵ���Ϊ���ڵ㣬���½����жϣ��ݹ���á�
ͬ�������������������򷽷�ͬ�ϡ�
Ҳ����˵�����յĽ���ֱ�ֻ�����������һ���ڵ�����������һ���ڵ����������������ڵ㶼���������������ڵ㶼����������
*/

struct TreeNode {
	int m_nvalue;
	TreeNode* m_pLeft;
	TreeNode* m_pRight;
};

TreeNode *getLCA(TreeNode *root, TreeNode *X, TreeNode *Y) {
	if (root == NULL) return NULL;              // ���������
	if (X == root || Y == root) return root;    // ֻ�и��ڵ�����
	// �ֱ��Ե�ǰ�ڵ�����ҽڵ�Ϊ�ڵ����
	TreeNode *left = getLCA(root->m_pLeft, X, Y);
	TreeNode *right = getLCA(root->m_pRight, X, Y);
	if (left == NULL)           // ������û���ҵ�
		return right;
	else if (right == NULL)     // ������û���ҵ�
		return left;
	else
		return root;
}

int main() 
{
	return 0;
}
