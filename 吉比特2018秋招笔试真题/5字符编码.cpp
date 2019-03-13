#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
��⣺����
*/

int solve(int s, int e, string& str) {
	if (s >= e)
		return 1;
	int mid = (s + e) / 2;
	if (str[mid] == '1') { // �����ֽ������
		return solve(s, mid, str) * solve(mid + 1, e, str) +
			solve(s, mid - 1, str) * solve(mid + 2, e, str);
	}
	else { // ��һ�ֽ������
		return solve(s, mid, str) * solve(mid + 1, e, str);
	}
}

int main() {
	string str;
	cin >> str;
	printf("%d\n", solve(0, str.size() - 1, str));
	return 0;
}

/*
xxx10yyy
*/
