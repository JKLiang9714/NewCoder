#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
���⣺�ж�һ���ַ����Ƿ���������һ���Ӵ����ж����βƴ�ӹ���
��⣺�Ӵ��ĳ��ȱ�����ԭ�����ȵ����ӣ�ö�ټ���
*/

int main()
{
	int i, j;
	string str;
	cin >> str;
	int len = str.length();
	for (i = 1; i <= len / 2; i++) {
		if (len % i != 0) continue;
		int substr_number = len / i;
		string sub_str = str.substr(0, i);
		for (j = 0; j < substr_number; j++) {
			string temp = str.substr(j * i, i);
			if (temp != sub_str) {
				break;
			}
		}
		if (j == substr_number) {
			cout << sub_str << endl;
			break;
		}
	}
	if (i > len / 2) cout << "false" << endl;
	return 0;
}

/*
abcbbcbbc
*/