// FileBase.cpp - Basic file operation support.
// Version: 0.0.0.1
// Written by Xiaoxuan4096. All rights reserved.

// Note that all the functions below won't throw any exceptions, even if an error occurred.
// You should be responsible to check whether your file operation is done correctly.

#include "FileBase.h"

#include <fstream>

#include <Windows.h> // Windows Only

void Xiaoxuan4096::Basic::File::createFile(std::wstring path) {
	appendFile(path, L"");
	return;
}
void Xiaoxuan4096::Basic::File::deleteFile(std::wstring path) { // This CANNOT be undone. Be careful!
	DeleteFile(path.c_str()); // Windows Only
	return;
}

void Xiaoxuan4096::Basic::File::appendFile(std::wstring path, std::wstring content) {
	std::wfstream fileAppend;
	fileAppend.open(path, std::ios::app);
	if (!fileAppend.is_open())
		return;
	fileAppend << content;
	fileAppend.close();
	return;
}
void Xiaoxuan4096::Basic::File::rewriteFile(std::wstring path, std::wstring content) {
	std::wfstream fileRewrite;
	fileRewrite.open(path, std::ios::out);
	if (!fileRewrite.is_open())
		return;
	fileRewrite << content;
	fileRewrite.close();
	return;
}

std::wstring Xiaoxuan4096::Basic::File::readFile(std::wstring path) {
	std::wfstream fileRead;
	std::wstring content = L"";
	fileRead.open(path, std::ios::in);
	if (!fileRead.is_open())
		return content;
	fileRead >> content;
	return content;
}

std::vector<std::wstring> Xiaoxuan4096::Basic::File::readFileByLines(std::wstring path) {
	std::vector<std::wstring> content;
	std::wfstream fileRead;
	std::wstring tmp;
	fileRead.open(path, std::ios::in);
	if (!fileRead.is_open())
		return content;
	while (getline(fileRead, tmp)) {
		if (fileRead.fail() || fileRead.bad()) {
			fileRead.close();
			content.clear();
			break;
		}
		content.push_back(tmp);
	}
	fileRead.close();
	return content;
}