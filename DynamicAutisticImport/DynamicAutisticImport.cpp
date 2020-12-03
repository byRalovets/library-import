#include <cstdio>
#include <Windows.h>
#include <tchar.h>
#include <iostream>

#define TARGET_EXE "AppThatOutputsString.exe"
#define TARGET_STR "Trump is president!"
#define NEW_STR "Biden is president!"

typedef int(__stdcall* REPLACESTRINGFUNCTION)(LPTSTR, const char*, const char*);

int main()
{
	HINSTANCE hModule = LoadLibrary(L"C:\\osasp\\AutisticLibrary\\Debug\\AutisticLibrary.dll");
	if (hModule == NULL) {
		printf("Failed to load library. GetLastError = %d\n", GetLastError());
		return -1;
	}
	REPLACESTRINGFUNCTION replaceStringFunction = (REPLACESTRINGFUNCTION)GetProcAddress(hModule, "_ReplaceString@12");
	if (replaceStringFunction == NULL) {
		printf("Failed to get function address. GetLastError = %d\n", GetLastError());
		FreeLibrary(hModule);
		return -1;
	}
	TCHAR processName[] = TEXT(TARGET_EXE);
	int pid = replaceStringFunction(processName, TARGET_STR, NEW_STR);
	if (pid != -1) {
		printf("String replaced successfully. Target process ID = %d.\n", pid);
	}
	else {
		printf("Failed to replace string.\n");
	}
	FreeLibrary(hModule);
}