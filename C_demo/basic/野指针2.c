#include <stdio.h>
#include <string.h>

struct Student
{
    char* name;  //û�б���ʼ�����򱣴����һ�����ֵ�� 
    int number;
};

int main()
{
    struct Student s;
    
    strcpy(s.name, "Delphi Tang"); // OOPS!���ַ������浽һ�������ַ�ռ䡣 
    
    s.number = 99;
    
    
    return 0;
}
