#include <stdio.h>
#include <windows.h>

unsigned __int16 getStringLength(char* string)
{
	unsigned __int16 stringLength = 0;

	while (string[stringLength] != '\0' && stringLength < 4096)
	{
		++stringLength;
	}

	return stringLength;
}

char* getFileName(char* string, const unsigned __int16 stringLength)
{
	unsigned __int16 splitIndex = stringLength;

	while (splitIndex != 0)
	{
		if (string[splitIndex] == '\\')
		{
			break;
		}

		--splitIndex;
	}

	if (splitIndex == 0)
	{
		return string;
	}
	else
	{
		return &string[splitIndex + 1];
	}
}

__int64 getFileSize(FILE* stream, const char* fileName)
{
	if (_fseeki64(stream, 0, SEEK_END))
	{
		printf("Error: unable to find file end: %s", fileName);
		Sleep(10000);
		exit(-1);
	}

	__int64 fileSize = _ftelli64(stream);

	rewind(stream);

	return fileSize;
}