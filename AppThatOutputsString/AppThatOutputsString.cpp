#include <iostream>
#include <Windows.h>

int main()
{   
    CHAR str[20] = "Trump is president!";
    for (int count = 0; ; count++) {
        printf("%d:%s\n", count, str);
        Sleep(1000);
    }
}