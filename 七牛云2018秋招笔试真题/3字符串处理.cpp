#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void solve(string s) {
	while (true) {
		string res;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] != s[i + 1]) {
				res.append(1, s[i]);
			}
			else {
				i++;            // ������ǰ����һ��
			}
		}
		if (res == s) break;    // ��ʾ�����ַ�û���ظ�
		else s = res;
	}
	if (s.empty()) printf("Yes\n");
	else printf("No\n");
}

int main() 
{
	int t = 0;
    string str;
	scanf("%d", &t);
	while (t--) {
		cin >> str;
        solve(str);
	}
	return 0;
}

/*
2
ABCCBA
ABCCCCCBBBBB
*/
