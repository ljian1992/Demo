#include <stdio.h>
#include <malloc.h>

int main()
{
    char* s = (char*)malloc(10);
    
    printf(s); // OOPS! �ڴ����ɹ�����δ��ʼ���� 
    
    free(s);
       
    return 0;
}

