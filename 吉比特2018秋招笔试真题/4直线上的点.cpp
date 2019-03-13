#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
��⣺���������һ��ֱ�ߣ�����������������Ա�������ֱ�ߣ����ڱ����Ĺ����У���ֱ�߻���������
�´�����������ֱͬ��ʱ���ֻ�ǰ�����ֱ�߶�Ӧ�Ĵ��ڵĵ�ĸ����ۼӡ�
�������ǾͿ����������ĳ�����ĳ��ֱ�������ĵ�ĸ�����
Ҫע����ǵڶ��������ʱ�򣬿���ֻ������i + 1 ~ size �C 1��ֱ�ߣ�
��Ϊ��֮ǰ�ĵ��ܹ���ɵ�ֱ���Ѿ������������Ҫ�ٴ���(a,b������ֱ�ߺ� b,a������ֱ����һ����)��
ע�⣺������ͬҲ�㹲�ߡ�
*/

class Point3D {
public:
	int x, y, z;
	Point3D() { x = y = z = 0; }
	Point3D(int a, int b, int c) { x = a; y = b; z = c; }
	bool equal(const Point3D& pt) const {
		return x == pt.x && y == pt.y && z == pt.z;
	}
};

class Line3D {
public:
	// dx / dz
	float kx;
	// dy / dz
	float ky;
	// dz == 0 ?
	bool bz;
	bool operator==(const Line3D &l) const {
		return kx == l.kx && ky == l.ky && bz == l.bz;
	}
	bool operator<(const Line3D &l) const {
		return kx < l.kx || (kx == l.kx && ky < l.ky);
	}
};

int maxPoints(vector<Point3D> points) {
	int maxNum = 0;
	for (size_t i = 0; i < points.size(); ++i) {// �������е�
		int sameNum = 0;
		int ptMaxCount = 0;
		map<Line3D, int> lineMap;
		for (size_t j = i + 1; j < points.size(); ++j) {// ��������i֮���������
			auto &p1 = points[i];
			auto &p2 = points[j];

			if (p1.equal(p2)) { // ������պ���ͬ
				sameNum++;
				continue;
			}

			// б��������㹲��
			Line3D line;
			int dz = p2.z - p1.z;
			if (dz == 0) {
				line.bz = true;
				line.kx = line.ky = 0;
			}
			else {
				line.bz = false;
				line.kx = (float)(p2.x - p1.x) / dz;
				line.ky = (float)(p2.y - p1.y) / dz;
			}

			// ����
			int count;
			if (lineMap.find(line) == lineMap.end())
				count = lineMap[line] = 1;
			else
				count = ++lineMap[line];

			ptMaxCount = max(ptMaxCount, count);
		}
		// 
		maxNum = max(ptMaxCount + sameNum + 1, maxNum);
	}
	return maxNum;
}

int main() {
	int n = 0;
	scanf("%d", &n);
	vector<Point3D> points;
	while (n--) {
		Point3D p;
		scanf("%d%d%d", &p.x, &p.y, &p.z);
		points.push_back(p);
	}
	printf("%d\n", maxPoints(points));
	return 0;
}

/*
4 
0 0 0 
1 1 1
-1 -1 -1 
0 1 0
*/
