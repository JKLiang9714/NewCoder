#include <iostream>
#include <cstdio>
using namespace std;

/*
���⣺���������ַ���������β������ţ�ʹ��ƥ��Ϸ� 
��⣺stringģ�� 
*/

string str, prefix;

int main() 
{
	cin >> str;
	int len = str.length();
	int cnt = 0;
	for (int i = 0; i < len; i++) {
		if (str[i] == '[') cnt++;
		else cnt--;
		if (cnt < 0) {
			cnt++;
			prefix += "[";
		}
	}
	cout << prefix + str + string(cnt, ']') << endl;
	return 0;
}

/*
][
[]]]]
[[[[]
*/
