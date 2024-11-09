// FileBase.cpp - Basic file operation support.
// Version: 0.0.0.0
// Written by Xiaoxuan4096. All rights reserved.

// Note that all the functions below won't throw any exceptions, even if an error occurred.
// You should be responsible to check whether the operation is done correctly.

#include "../../../Headers/Basic/FileBase/FileBase.h"

#include <fstream>

#include <cstdio>

void Xiaoxuan4096::Basic::File::createFile(std::wstring path) {
	std::fstream fileCreator;
	fileCreator.open(path.c_str(), std::ios::app);
	return;
}

void Xiaoxuan4096::Basic::File::deleteFile(std::wstring path) {
}

void Xiaoxuan4096::Basic::File::appendFile(std::wstring path, std::wstring content) {
	std::fstream fileAppend;
	fileAppend.open(path.c_str(), std::ios::app);
	if (!fileAppend.is_open())
		return;
}

void Xiaoxuan4096::Basic::File::rewriteFile(std::wstring path, std::wstring content) {
}

std::wstring Xiaoxuan4096::Basic::File::readFile(std::wstring path) {
	return std::wstring();
}

std::vector<std::wstring> Xiaoxuan4096::Basic::File::readFileByLines(std::wstring path) {
	return std::vector<std::wstring>();
}
