#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
  string code;// ����
  // ��ȡ���룬ֱ��Ctrl+Z
  char c = getchar(); // ��ȡ�����ַ�
  while (c != EOF){
    code += c;
    c = getchar();
  }
  
  // ��������
  int res = 0;// ע��ͳ�Ƹ���
  bool c1 = false;// ��һ��ע�ͷ�ʽ(����ע��)
  bool c2 = false; // �ڶ���ע�ͷ�ʽ(����ע��)
  bool qs = false;// ˫���Ŵ���

  // ���������е�ÿһ�ַ�
  for (int i = 0; i < code.size(); i++) {
    if (code[i] == '\n') { // ��������
      c1 = false;// ����ע�ͽ���
    } else if (c1) {
    } else if (c2) {
      // ͳ��
      if (i + 1 < code.size() 
          && code[i] == '*'
          && code[i + 1] == '/') { // ����ע�ͽ�β�ж�
        c2 = false;
        i++;
      }
    } else if (qs) {
      if (code[i] == '"'){ // ˫���Ž����ж�
        int t = false;
        for (int j = i - 1; j >= 0; j--)
          if (code[j] == '\\') {
            t++;
          } else {
            break;
          }
          if (t % 2 == 0) qs = 0;
        }
    } else if (code[i] == '"') { // ˫���ſ�ʼ
      qs = true;
    } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '/') { // ����ע�Ϳ�ʼ
      c1 = true;
      res++;
      i++;
    } else if (i + 1 < code.size() && code[i] == '/' && code[i + 1] == '*') { // ����ע�Ϳ�ʼ
      c2 = true;
      res++;
      i++;
    } else if (code[i] == '\'') {// ת���ַ�
      if (code[i + 1] == '\\')
        i += 3;
      else
        i += 2;
    }
  }
  printf("%d",res);
  return 0;
}

/*
// line comment
// line comment2
int main() {
  return 0;
}
*/
