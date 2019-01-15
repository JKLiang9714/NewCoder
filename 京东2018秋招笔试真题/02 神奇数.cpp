#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

/*
��⣺�ж�һ�����Ƿ��ܲ�ɺ���ȵ�������
	������ת��Ϊ�ַ������������ö�ٲ��λ�ü��� 
*/

const int MAXN = 1000000;
char str[MAXN + 1];

int cmp(int a, int b) {
	return a > b;
}

int fun(string &s) {
	int len = s.length();
	for (int i = 1; i < len; i++) {
		string x = s.substr(0, i);
		string y = s.substr(i, len - i);
		if (atoi(x.c_str()) == atoi(y.c_str())) {
			return 1;
		}
	}
	return 0;
}

int main() 
{
	int l, r, num;
	scanf("%d%d", &l, &r);
	int ans = 0;
	for (int i = l; i <= r; i++) {
		sprintf(str, "%d", i);
		sort(str, str + strlen(str), cmp);     // �Ӵ�С����Ϊ�˱���ǰ��0 
		sscanf(str, "%d", &num);
		string s = to_string(num);
		ans += fun(s);
	} 
	printf("%d\n", ans);
	return 0;
}

/*
1 50
*/
