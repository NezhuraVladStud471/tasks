#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <iostream>

#define root L"C:"

void findFile(std::wstring path, std::wstring substr) {
	std::wstring fileName = path + L"\\*";
	WIN32_FIND_DATAW fileData;
	HANDLE h = FindFirstFileW(fileName.c_str(), &fileData);
	if (h == INVALID_HANDLE_VALUE) {
		return;
	}
	do {
		if (lstrcmpW(fileData.cFileName, L".") == 0 || lstrcmpW(fileData.cFileName, L"..") == 0) continue;
		std::wstring str = fileData.cFileName;
		fileName = path + L"\\" + str;
		if (str.find(substr) != std::wstring::npos) std::wcout << fileName << std::endl;
		findFile(fileName, substr);
	} while (FindNextFileW(h, &fileData));
	return;
};

int wmain(int argc, wchar_t* argv[]) {
	wprintf(L"Looking for %s substring \n", argv[1]);
	findFile(root, argv[1]);
	system("pause");
}