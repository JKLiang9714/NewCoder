#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/*
Unix·�������¹���
    ·�����ļ������ļ�������/���ɡ�
    ���������/����Ϊ����/��
    .��ʾ����Ŀ¼��
    ..��ʾ�����ϼ�Ŀ¼��
    �ʼ��/��ʾ��Ŀ¼�����Ϸ��ص���Ŀ¼�����������Ϸ��� 
*/

int main() 
{
	string path;
    vector<string> dir;
    cin >> path;
    int len = path.size();
    for (int i = 0; i < len; i++) {
        if (path[i] == '/') continue;
        if (path[i] == '.') {
            if (i + 1 < len && path[i + 1] == '/') {
                i++;
                continue;
            } else if (i + 1 < len && path[i + 1] == '.') {
                i += 2;
                if (!dir.empty()) dir.pop_back();
                continue;
            }
        }
        string name;
        name.append(1, path[i]);
        while (path[++i] != '/') {
            name.append(1, path[i]);
        }
        dir.push_back(name);
    }
    if (dir.empty()) printf("/\n");
    else {
        int dirSize = dir.size();
        for (int i = 0; i < dirSize; i++) {
            cout << '/' << dir[i];
        }
    }
	return 0;
}

/*
/a/./b/../../c/
*/
