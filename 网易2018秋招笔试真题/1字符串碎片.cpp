#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
���⣺��s�����������Ӵ��ж��ٸ� 
��⣺ö�� 
*/

int main() 
{
	string s;
	cin >> s;
	int len = s.size();
	int cnt = 1;
	for (int i = 1; i < len; i++) {
		if (s[i] != s[i - 1]) cnt++;
	}
	double ans = len * 1.0 / cnt;
	printf("%.2lf\n", ans);
	return 0;
}

/*
aaabbaaac
*/
