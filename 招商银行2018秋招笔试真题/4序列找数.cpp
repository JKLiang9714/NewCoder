#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

/*
���⣺�ӷǸ���������0��1��2��.��n�и�����������n�����������У����ҳ�δ�����ڸ��������е��Ǹ���
��⣺��ϣ��
*/

int main()
{
    int n = 0;
    scanf("%d", &n);
    vector<bool> vec(n + 1, false);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		vec[t] = true;
	}
    for (int i = 0; i < n; i++) {
        if (!vec[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

/*
3 3 0 1
*/
