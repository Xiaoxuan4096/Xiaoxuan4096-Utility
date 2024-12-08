// FileBase.cpp - Basic file operation support.
// Version: 0.0.0.6
// Written by Xiaoxuan4096. All rights reserved.

// Note that all the functions below won't throw any exceptions, even if an error occurred.
// You should be responsible to check whether your file operation is done correctly.

#include "FileBase.h"

#include <fstream>
#include <filesystem>

void Xiaoxuan4096::Basic::File::createFile(std::wstring path) {
	appendFile(path, L"");
	return;
}
void Xiaoxuan4096::Basic::File::deleteFile(std::wstring path) { // This CANNOT be undone. Be careful!
	if (std::filesystem::exists(path))
		std::filesystem::remove(path);
	return;
}

void Xiaoxuan4096::Basic::File::appendFile(std::wstring path, std::wstring content) {
	std::wfstream fileAppender;
	fileAppender.open(path, std::ios::app);
	if (!fileAppender.is_open())
		return;
	fileAppender << content;
	fileAppender.close();
	return;
}
void Xiaoxuan4096::Basic::File::rewriteFile(std::wstring path, std::wstring content) {
	std::wfstream fileRewriter;
	fileRewriter.open(path, std::ios::out);
	if (!fileRewriter.is_open())
		return;
	fileRewriter << content;
	fileRewriter.close();
	return;
}

void Xiaoxuan4096::Basic::File::createEmptyDirectory(std::wstring path) {
	if (!std::filesystem::exists(path))
		std::filesystem::create_directory(path);
	return;
}
void Xiaoxuan4096::Basic::File::removeEmptyDirectory(std::wstring path) { // Can only remove empty directory.
	if (std::filesystem::exists(path) && std::filesystem::is_empty(path))
		std::filesystem::remove(path);
	return;
}
void Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(std::wstring path) { // This CANNOT be undone. Be careful!
	if (std::filesystem::exists(path))
		std::filesystem::remove_all(path);
	return;
}

void Xiaoxuan4096::Basic::File::copySingleFile(std::wstring location, std::wstring destination) noexcept { // Will overwrite existing files. Be careful!
	if (!std::filesystem::exists(location))
		return;
	if (!std::filesystem::exists(destination))
		createEmptyDirectory(destination);
	std::filesystem::copy_file(location, destination, std::filesystem::copy_options::overwrite_existing);
	return;
}
void Xiaoxuan4096::Basic::File::copyDirectoryAndAllContents(std::wstring location, std::wstring destination) noexcept { // Will overwrite existing files. Be careful!
	if (!std::filesystem::exists(location))
		return;
	if (!std::filesystem::exists(destination))
		createEmptyDirectory(destination);
	std::filesystem::copy(location, destination, std::filesystem::copy_options::overwrite_existing);
	return;
}

std::wstring Xiaoxuan4096::Basic::File::readFile(std::wstring path) {
	std::wfstream fileReader;
	std::wstring content = L"";
	fileReader.open(path, std::ios::in);
	if (!fileReader.is_open())
		return content;
	fileReader >> content;
	return content;
}

bool Xiaoxuan4096::Basic::File::existFile(std::wstring path) {
	return std::filesystem::exists(path);
}