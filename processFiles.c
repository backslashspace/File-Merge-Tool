#include <stdio.h>
#include <windows.h>

#define OutputFileName "monoOut.txt"
#define TransferBuffer 65535

void processFiles(char** fileNames, __int32 fileCount)
{
	FILE* outFile = fopen(OutputFileName, "wb");
	if (outFile == NULL)
	{
		printf("Error: unable to open file at "OutputFileName);
		Sleep(10000);
		exit(-1);
	}

	//

	char* buffer = malloc(TransferBuffer);
	if (buffer == NULL)
	{
		printf("Error: unable to allocate buffer of %i bytes", TransferBuffer);
		Sleep(10000);
		exit(-1);
	}

	//

	FILE* currentFile;
	__int64 fileSize = 0;

	for (__int32 i = 1; i < fileCount; ++i)
	{
		#pragma warning(disable : 4996)
		currentFile = fopen(fileNames[i], "rb");
		if (currentFile == NULL)
		{
			printf("Error: unable to open file at: %s", fileNames[i]);
			Sleep(10000);
			exit(-1);
		}

		fileSize = getFileSize(currentFile, fileNames[i]);

		// copy

		while (fileSize != 0)
		{
			if (fileSize >= TransferBuffer)
			{
				fileSize -= TransferBuffer;

				fread(buffer, 1, TransferBuffer, currentFile);
				fwrite(buffer, 1, TransferBuffer, outFile);
			}
			else
			{
				fread(buffer, 1, fileSize, currentFile);
				fwrite(buffer, 1, fileSize, outFile);

				fileSize = 0;
			}
		}

		fclose(currentFile);
	}

	fclose(outFile);

	free(buffer);
}