#include <stdio.h>
#include <windows.h>
#include "modules.h"

static void PrintFileNames(char* file)
{
	unsigned __int16 stringLength = getStringLength(file);

	char* fileName = getFileName(file, stringLength);

	printf("File: %s\n", fileName);
}

__int32 main(__int32 argc, char** argv)
{
	SetConsoleOutputCP(1252);
	SetConsoleCP(1252);
	SetFileApisToOEM();

	if (argc < 2)
	{
		printf("no files specified");
		Sleep(5120);

		exit(1);
	}

	printf("todo:\n");

	for (__int32 i = 1; i < argc; ++i)
	{
		PrintFileNames(argv[i]);
	}

	processFiles(argv, argc);

	return 0;
}