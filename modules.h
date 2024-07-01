#pragma once

unsigned __int16 getStringLength(char* string);

char* getFileName(char* string, const unsigned __int16 stringLength);

void processFiles(char** fileNames, __int32 fileCount);