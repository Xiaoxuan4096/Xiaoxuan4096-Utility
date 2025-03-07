// FileEditor.cpp - File operation.
// Version: 0.0.0.3
// Written by Xiaoxuan4096.

#include "FileEditor.h"
#include "../BasicSupport/FileBase/FileBase.h"

Xiaoxuan4096::File::FileEditor::FileEditor() {
	return;
}
Xiaoxuan4096::File::FileEditor::FileEditor(std::wstring fileDirectory, std::wstring fileName, std::wstring cacheDirectory, FileEditorCategory category) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	this->cacheDirectory = cacheDirectory;
	this->category = category;
	fileContent.clear();
	return;
}
void Xiaoxuan4096::File::FileEditor::linkWithFile(std::wstring fileDirectory, std::wstring fileName) {
	this->fileDirectory = fileDirectory;
	this->fileName = fileName;
	fileContent.clear();

	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithFile() {
	fileDirectory = L"";
	fileName = L"";
	fileContent.clear();

	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);

	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedFileName() {
	return fileName;
}
void Xiaoxuan4096::File::FileEditor::linkWithCacheDirectory(std::wstring cacheDirectory) {
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::copyDirectoryAndAllContents(this->cacheDirectory, cacheDirectory);
	else
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(this->cacheDirectory);
	this->cacheDirectory = cacheDirectory;

	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithCacheDirectory() {
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);
	cacheDirectory = L"";

	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedCacheDirectoryName() {
	return cacheDirectory;
}
std::wstring Xiaoxuan4096::File::FileEditor::getObjectUniqueIdentityString() {
	return ouids.getObjectUniqueIdentityString();
}

void Xiaoxuan4096::File::FileEditor::createFile() {
	if (Xiaoxuan4096::Basic::File::existFile(fileDirectory + fileName))
		return;

	Xiaoxuan4096::Basic::File::createFile(fileDirectory + fileName);

	return;
}
void Xiaoxuan4096::File::FileEditor::renameFile(std::wstring newFileName) {
	if (option == FileOption::Skip && Xiaoxuan4096::Basic::File::existFile(fileDirectory + newFileName))
		return;

	std::wstring oldFileName = fileName;
	fileName = newFileName;
	createFile();
	
	Xiaoxuan4096::Basic::File::copySingleFile(fileDirectory + oldFileName, fileDirectory + fileName);
}
void Xiaoxuan4096::File::FileEditor::deleteFile() {
}

void Xiaoxuan4096::File::FileEditor::createDirectory() {
}
void Xiaoxuan4096::File::FileEditor::renameDirectory(std::wstring newFileDirectory) {
}
void Xiaoxuan4096::File::FileEditor::deleteDirectory() {
}

void Xiaoxuan4096::File::FileEditor::append(std::wstring content) {
	Xiaoxuan4096::Basic::File::appendFile(fileDirectory + fileName, content);

	return;
}
void Xiaoxuan4096::File::FileEditor::rewrite(std::wstring content) {
	Xiaoxuan4096::Basic::File::rewriteFile(fileDirectory + fileName, content);

	return;
}

std::wstring Xiaoxuan4096::File::FileEditor::read() {
	return std::wstring();
}
