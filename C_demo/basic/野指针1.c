#include <stdio.h>

char* func()
{
    char p[] = "Delphi Tang";
    
    return p;
}

int main()
{
    char* s = func();
    
    printf("%s\n", s); // OOPS! ָ����ָ��ı�����ָ��ʹ��֮ǰ�ѱ����� 
    
    return 0;
}
