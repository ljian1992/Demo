#include <stdio.h>
#include <malloc.h>
#include <string.h>

void func(char* p)
{
    printf("%s\n", p);
    free(p);  //�黹�˿ռ� 
}

int main()
{
    char* s = (char*)malloc(5);
    
    strcpy(s, "Delphi Tang");
    
    func(s);
    
    printf("%s\n", s); // OOPS! ʹ���Ѿ��ͷŹ����ָ�롣 
    
    return 0;
}
