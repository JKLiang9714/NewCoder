#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
���⣺��t���е��ַ��滻s���е��ַ���ʹs���ֵ������ 
��⣺����һ����� 
*/

int cmp(char a, char b) {
	return a > b;
}

int main() 
{
	string s, t;
	cin >> s >> t;
	sort(t.begin(), t.end(), cmp);
	int pos = 0; 
	for (int i = 0; i < s.size(); i++) { 
		if(s[i] < t[pos]) { 
			s[i] = t[pos]; 
			pos++; 
		} 
	}
	cout << s << endl;
	return 0;
}

/*
fedcba
ee 
*/
