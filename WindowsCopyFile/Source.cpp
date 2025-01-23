#include <windows.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
	if (argc != 3) {
		printf("Not 2 Files Were Given!");
		return 1;
	}

	int Size1 = MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, nullptr, 0);
	wchar_t* File1 = new wchar_t[Size1];
	MultiByteToWideChar(CP_UTF8, 0, argv[1], -1, File1, Size1);

	int Size2 = MultiByteToWideChar(CP_UTF8, 0, argv[2], -1, nullptr, 0);
	wchar_t* File2 = new wchar_t[Size2];
	MultiByteToWideChar(CP_UTF8, 0, argv[2], -1, File2, Size2);

	if (!CopyFile(File1, File2, FALSE)) {
		printf("File Copy Error. %d", GetLastError());
		return 1;
	}
	return 0;
}