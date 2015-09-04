#include <stdio.h>
#include <string.h>

struct Student
{
    char* name;  //没有被初始化，则保存的是一个随机值。 
    int number;
};

int main()
{
    struct Student s;
    
    strcpy(s.name, "Delphi Tang"); // OOPS!把字符串保存到一个随机地址空间。 
    
    s.number = 99;
    
    
    return 0;
}
