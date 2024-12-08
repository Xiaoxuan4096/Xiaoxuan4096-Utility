// FileEditor.cpp - File operation.
// Version: 0.0.0.1
// Written by Xiaoxuan4096.

#include "FileEditor.h"
#include "../BasicSupport/FileBase/FileBase.h"

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
void Xiaoxuan4096::File::FileEditor::linkWithCacheDirectory(std::wstring cacheDirectory) { // Lack of code for deleting old cache files. Need improvement.
	Xiaoxuan4096::Basic::File::createEmptyDirectory(cacheDirectory);
	this->cacheDirectory = cacheDirectory;
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);
	return;
}
void Xiaoxuan4096::File::FileEditor::unlinkWithCacheDirectory() { // Lack of code for deleting cache files. Need improvement.
	cacheDirectory = L"";
	if (cacheDirectory != L"")
		Xiaoxuan4096::Basic::File::removeDirectoryAndAllContents(cacheDirectory);
	return;
}
std::wstring Xiaoxuan4096::File::FileEditor::getLinkedCacheDirectoryName() {
	return cacheDirectory;
}