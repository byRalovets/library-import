#include <cstdio>
#include <tchar.h>
#include <Windows.h>
#include <iostream>

#include "dllmain.cpp"

#define TARGET_EXE "AppThatOutputsString.exe"
#define TARGET_STR "Trump is president!"
#define NEW_STR "Biden is president!"

using namespace std;

extern "C" __declspec(dllexport) int __stdcall ReplaceString(LPTSTR szTargetProcessName, const char* stringToFind, const char* stringToReplace);

int main()
{
    TCHAR processName[] = TEXT(TARGET_EXE);
    int pid;
    if ((pid = ReplaceString(processName, TARGET_STR, NEW_STR)) != -1) {
        printf("String replaced successfully. Target process ID = %d.\n", pid);
    }
    else {
        printf("Failed to replace string.\n");
    }
}