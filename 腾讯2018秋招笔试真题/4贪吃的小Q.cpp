#include <iostream>
#include <cstdio>
#include <algorithm> 
using namespace std;

/*
��⣺���� 
*/
int n, m;

bool checkEnough(int num) {
	int sumNum = m;
	for (int i = 0; i < n; i++) {
		sumNum -= num;
		if (sumNum < 0) return false;
		num = (num + 1) / 2;	// ע�ⲻ��num /= 2 
	}
	return true;
}

int main() 
{
	scanf("%d%d", &n, &m);
	int l = 1, r = m;
	while (l < r) {
		int mid = (l + r + 1) / 2;
		int yes = checkEnough(mid);
		if (yes) l = mid;
		else r = mid - 1;
	}
	printf("%d\n", l);
	return 0;
}

/*
3 7
*/
