#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

/*
���⣺��s�������ֵ������������� 
��⣺Ϊ���ٴ�����������algorithm�����max_element���� 
*/

int main() 
{
	string s, t;
	cin >> s;
	while (!s.empty()) {
		auto it = max_element(s.begin(), s.end());
		t += *it;
		s.erase(s.begin(), it + 1);
	}
	cout << t << endl;
	return 0;
}

/*
test
*/
